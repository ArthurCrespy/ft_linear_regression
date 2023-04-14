/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_regression.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:48:51 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/14 16:48:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef FT_LINEAR_REGRESSION_H
# define FT_LINEAR_REGRESSION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/* ---------- FT_UTILS ---------- */
long long	ft_strlen(char *str);
int			ft_strchr(char *str, char c);
char		*ft_calloc(size_t nb, size_t size);
char		*ft_strjoin(char *s1, char *s2);

/* ------------ GNL ------------- */
char		*get_next_line(int fd);

#endif
