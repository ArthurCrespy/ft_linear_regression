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

#ifndef LEARNING_RATE
# define LEARNING_RATE 0.0001
#endif

#ifndef LEARNING_TOLERANCE
# define LEARNING_TOLERANCE 0.0000001
#endif

#ifndef FT_LINEAR_REGRESSION_H
# define FT_LINEAR_REGRESSION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/* ---------- FT_LEN ------------ */
long long	ft_strlen(char *str);
long long   ft_nbrlen(double nbr);
long long	ft_datasetlen(int *dataset);

/* ---------- FT_SPLIT ---------- */
char	**ft_split(char *str, char c);

/* ---------- FT_UTILS ---------- */
int			ft_isdigit(char *str);
char		*ft_strchr(char *str, int c);
int			ft_atoi(char *str);
char		*ft_calloc(size_t nb, size_t size);
char		*ft_strjoin(char *s1, char *s2);

/* ------------ GNL ------------- */
char		*get_next_line(int fd);

#endif
