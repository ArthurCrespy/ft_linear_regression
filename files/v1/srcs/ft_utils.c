/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:03:07 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/14 19:20:21 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_linear_regression.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n'))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}


char	*ft_strchr(char *str, int c)
{
	long long	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (str + ft_strlen(str));
	while (str[i] && str[i] != (char)c)
		i++;
	if (i == ft_strlen(str))
		return (NULL);
	else
		return (str + i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += (str[i++] - '0');
	}
	return (result * sign);
}

char	*ft_calloc(size_t nb, size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	if (nb == 0 || size == 0)
		return (NULL);
	if ((nb * size) / size != nb)
		return (NULL);
	result = malloc(nb * size);
	if (!result)
		return (NULL);
	while (i < nb * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i_s1;
	int	i_s2;
	char	*result;

	i_s1 = 0;
	i_s2 = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (s1)
	{
	    while (s1[i_s1])
		{
			result[i_s1] = s1[i_s1];
			i_s1++;
		}
		free(s1);
	}
	if (s2)
	{
		while (s2[i_s2])
		{
			result[i_s1 + i_s2] = s2[i_s2];
			i_s2++;
		}
	}
	result[i_s1 + i_s2] = '\0';
	return (result);
}
