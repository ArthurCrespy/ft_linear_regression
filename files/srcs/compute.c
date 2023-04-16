/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:20:05 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/15 23:20:05 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_linear_regression.h"

int main(int argc, char **argv)
{
	int fd;
	int price;
	int mileage;

	if (argc != 2)
		return (1);
	mileage = ft_atoi(argv[1]);
	if (mileage < 0)
		return (printf("Mileage must be positive\n"), 1);
	fd = open(".tetha", O_RDONLY);
	price = 0;
	if (fd == -1)
		return (printf("Estimated price: %d\n", price), 1);
	price = ft_atoi(get_next_line(fd)) + (ft_atoi(get_next_line(fd)) * mileage);
	printf("Estimated price: %d\n", price);
	close(fd);
	return (0);
}