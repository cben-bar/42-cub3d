/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:29 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:42:37 by mgolinva         ###   ########.fr       */
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
		if (flat[i] == '\n' || flat[i] == '\0')
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
	if (len < j)
		len = j;
	return (len);
}

int	is_in_charset(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	if (c == ' ' || c == '\n')
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

void	fill_struct(t_data *data, char *flat, int i, int j)
{
	int	k;

	while (flat[i] && j < data->pars->height_map)
	{
		data->pars->map[j] = malloc(sizeof(char) * (check_len(&flat[i]) + 1));
		if (!data->pars->map[j])
			free_and_quit("malloc error", data);
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
