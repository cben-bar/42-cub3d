/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:08:54 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/05 14:34:42 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	ft_strsuperdup(char **split, int i, const char *s, size_t len)
{
	size_t	j;

	j = 0;
	split[i] = malloc (len + 1);
	if (!split[i])
	{
		while (i >= 0)
		{
			free (split[i]);
			i--;
		}
		free (split);
		return (0);
	}
	else
	{
		while (s[j] && j < len)
		{
			split[i][j] = s[j];
			j++;
		}
		split[i][j] = 0;
	}
	return (1);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	i_b;
	size_t	i_e;

	i_b = 0;
	i_e = 0;
	i = 0;
	while (s[i_e])
	{
		if (s[i_e] == c)
		{
			if (i_e > i_b)
				i++;
			i_b = i_e + 1;
		}
		i_e++;
	}
	if (i_e > i_b)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	i_b;
	size_t	i_e;

	i_b = 0;
	i_e = 0;
	i = 0;
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i_e])
	{
		if (s[i_e] == c)
		{
			if (i_e > i_b && !ft_strsuperdup (split, i++, s + i_b, i_e - i_b))
				return (NULL);
			i_b = i_e + 1;
		}
		i_e++;
	}
	if (i_e > i_b && !ft_strsuperdup (split, i++, s + i_b, i_e - i_b))
		return (NULL);
	split[i] = 0;
	return (split);
}
