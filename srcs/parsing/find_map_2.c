/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:29 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/15 15:08:12 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	find_len_map(char *flat, int i)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (flat[i])
	{
		if (flat[i] == '\n')
		{
			if (len < j)
				len = j;
			j = 0;
		}
		else if (flat[i] >= 9 && flat[i] <= 13)
			j += 4;
		else
			j++;
		i++;
	}
	return (len);
}

int	is_in_charset(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	if (c == ' ' || (c >= 9 && c <= 13))
		return (3);
	return (0);
}

int	len_replace(char *dst)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dst[i] = ' ';
		i++;
	}
	return (4);
}

int	check_len(char *flat)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (flat[i] && flat[i] != '\n')
	{
		if (flat[i] >= 9 && flat[i] <= 13)
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}

void	fill_struct(t_data *data, char *flat, int i)
{
	int	j;
	int	k;

	j = 0;
	while (flat[i] && j < data->pars->height_map)
	{
		data->pars->map[j] = malloc(sizeof(char) * (check_len(&flat[i]) + 1));
		k = 0;
		while (flat[i] && flat[i] != '\n')
		{
			if (flat[i] >= 9 && flat[i] <= 13)
				k += len_replace(&data->pars->map[j][k]);
			else
			{
				data->pars->map[j][k] = flat[i];
				k++;
			}
			i++;
		}
		data->pars->map[j][k] = '\0';
		while (flat[i] && flat[i] == '\n')
			i++;
		j++;
	}
	data->pars->map[j] = 0;
}
