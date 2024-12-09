/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:11:51 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/16 14:11:54 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_linear_regression.h"

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