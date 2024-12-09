/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:46:32 by acrespy           #+#    #+#             */
/*   Updated: 2023/04/16 00:46:34 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_linear_regression.h"

void	ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

int	ft_size_word(const char *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] && str[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

int	ft_count_word(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str && str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	if (start > (unsigned int)ft_strlen(s))
		return ("");
	while (s[start + length] && length < len)
		length++;
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start + i] && i < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**strs;

	i = 0;
	j = 0;
	word = ft_count_word(str, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (j < word)
	{
		while (str[i] == c)
			i++;
		size = ft_size_word(str, c, i);
		strs[j] = ft_substr(str, i, size);
		if (!strs[j])
			ft_free(strs, j);
		i += size;
		j++;
	}
	strs[j] = 0;
	return (strs);
}