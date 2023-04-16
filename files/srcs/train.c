/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:20:25 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/15 23:47:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_linear_regression.h"

int dataset_size(char *path)
{
	int i;
	int fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
}

int dataset_save_line(char *line, int i)
{
	int result;
	char **split;

	result = 0;
	split = ft_split(line, ',');
	if (!split)
		return (-1);
	if (!ft_isdigit(split[i]))
	{
		free(split[0]);
		free(split[1]);
		free(split);
		return (-1);
	}
	else
	{
		result = ft_atoi(split[i]);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	return (result);
}

int **dataset_parse(char *path)
{
	int i;
	int fd;
	int size;
	char *line;
	int **dataset;

	i = 0;
	size = dataset_size(path);
	if (size == 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dataset = malloc(sizeof(int) * size * 2);
	dataset[0] = (int *)malloc(sizeof(int) * size);
	dataset[1] = (int *)malloc(sizeof(int) * size);
	if (!dataset || !dataset[0] || !dataset[1])
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		dataset[0][i] = dataset_save_line(line, 0);
		dataset[1][i] = dataset_save_line(line, 1);
		if (dataset[0][i] == -1 || dataset[1][i] == -1)
			;
		else
			i++;
	}
	close(fd);
	return (dataset);
}

int theta_create(void)
{
	int fd;

	fd = open(".tetha", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	write(fd, "0\n0", 3);
	close(fd);
	return (0);
}

int theta_update(double th0, double th1)
{
	int fd;

	fd = open(".tetha", O_RDWR);
	if (fd == -1)
		return (1);
	write(fd, &th0, ft_nbrlen(th0));
	write(fd, "\n", 1);
	write(fd, &th1, ft_nbrlen(th1));
	close(fd);
	return (0);
}

void train(int *mileage, int *price, double th0, double th1)
{
	int i;
	int j;
	double cost;
	double diff;
	double delta_0;
	double delta_1;

	j = 0;
	while (j < 10)
	{
		i = 0;
		cost = 0;
		while (i < ft_datasetlen(mileage))
		{
			diff = (th0 + (th1 * (double) mileage[i]));
			delta_0 = diff - (double) price[i];
			delta_1 = (diff - (double) price[i]) * (double) mileage[i];
			cost += (diff - (double) price[i]) * (diff - (double) price[i]);
			printf("diff: %f, delta_0: %f, delta_1: %f, cost: %f\n", diff, delta_0, delta_1, cost);
			i++;
		}
		th0 = LEARNING_RATE * (1 / (double) ft_datasetlen(mileage)) * delta_0;
		th1 = LEARNING_RATE * (1 / (double) ft_datasetlen(mileage)) * delta_1;
		j++;
	}
	printf("th0: %f, th1: %f, cost: %f\n", th0, th1, cost);
	theta_update(th0, th1);
}

int main(int argc, char **argv)
{
	double th0;
	double th1;
	int **dataset;

	th0 = 0;
	th1 = 0;
	if (argc != 2)
		return (1);
	if (theta_create() == 1)
		return (1);
	dataset = dataset_parse(argv[1]);
	if (!dataset || !dataset[0] || !dataset[1])
		return (1);
	//train(dataset[0], dataset[1], th0, th1);
	gradientDescent(dataset[0], dataset[1], ft_datasetlen(dataset[0]), &th0, &th1);
	return (0);
}
