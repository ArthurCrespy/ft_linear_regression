/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:50:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/16 13:50:44 by acrespy          ###   ########.fr       */
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