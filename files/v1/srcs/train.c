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

void train(int *mileage, int *price, double th0, double th1)
{
	int i;
	int j;
	double cost;
	double diff;
	double delta_0;
	double delta_1;

	j = 0;
	while (j < 100)
	{
		i = 0;
		cost = 0;
		diff = 0;
		delta_0 = 0;
		delta_1 = 0;
		while (i < ft_datasetlen(mileage))
		{
			diff += (th0 + (th1 * (double) mileage[i]));
			delta_0 += diff - (double) price[i];
			delta_1 += (diff - (double) price[i]) * (double) mileage[i];
			// cost += (diff - (double) price[i]) * (diff - (double) price[i]);
			//printf("diff: %f, delta_0: %f, delta_1: %f, cost: %f\n", diff, delta_0, delta_1, cost);
			i++;
		}
		th0 = LEARNING_RATE * (1 / (double) ft_datasetlen(mileage)) * delta_0;
		th1 = LEARNING_RATE * (1 / (double) ft_datasetlen(mileage)) * delta_1;
		printf("th0: %f, th1: %f, cost: %f\n", th0, th1, cost);
		j++;
	}
	printf("th0: %f, th1: %f, cost: %f\n", th0, th1, cost);
	printf("Estimated price: %f\n", th0 + (th1 * 240000));
	theta_update(th0, th1);
}

int main(int argc, char **argv)
{
	int i = 0;
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
	train(dataset[0], dataset[1], th0, th1);
	return (0);
}
