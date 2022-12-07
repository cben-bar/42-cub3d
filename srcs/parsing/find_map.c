/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:37 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:41:21 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	find_h_map(char *flat, int i)
{
	int	h;

	h = 0;
	while (flat[i])
	{
		while (flat[i] && flat[i] == '\n')
			i++;
		if (flat[i])
			h++;
		while (flat[i] && flat[i] != '\n')
			i++;
	}
	return (h);
}

int	find_map_info(t_data *data, char *flat, int i)
{
	data->pars->height_map = find_h_map(flat, i);
	if (data->pars->height_map < 2)
		return (0);
	data->pars->map = malloc(sizeof(char *) * (data->pars->height_map + 1));
	if (!data->pars->map)
		return (0);
	data->pars->len_map = find_len_map(flat, i);
	fill_struct(data, flat, i, 0);
	return (1);
}

int	get_map_begginning(char *flat)
{
	int	i;
	int	beg;

	i = 0;
	while (flat[i])
	{
		if (flat[i] == '\n')
		{
			i ++;
			while (flat[i] && is_in_charset(flat[i]) == 3)
				i ++;
			beg = i;
			while (flat[i] && is_in_charset(flat[i]) != 0 && flat[i] != '\n')
				i ++;
			if (flat[i] == '\n')
			{
				while ((flat[beg - 1] == ' ')
					&& (flat[beg - 1] != '\n'))
					beg --;
				return (beg);
			}
		}
		i ++;
	}
	return (i);
}

t_bool	is_map_last_elem(char *flat, int beg)
{
	int		i;
	int		nl_ct;
	size_t	flat_len;

	i = beg - 1;
	flat_len = ft_strlen(flat);
	while ((size_t)i < flat_len && is_in_charset(flat[i]) != 0)
	{
		nl_ct = 0;
		i ++;
		while (((flat[i])
				&& (flat[i] == ' ' || flat[i] == 10))
			|| (flat[i] && nl_ct > 1 && flat[i] == 9))
		{
			if (flat[i] == '\n')
				nl_ct ++;
			i ++;
		}
		if (nl_ct > 1 && (size_t)i < flat_len)
			return (false);
	}
	if ((size_t)i == flat_len)
		return (true);
	else
		return (false);
}

void	find_map(char *flat, t_data *data)
{
	int	beg;

	beg = get_map_begginning(flat);
	if (is_map_last_elem(flat, beg) == false)
	{
		free(flat);
		free_and_quit("Invalid map", data);
	}
	if ((size_t)beg == ft_strlen(flat))
	{
		free(flat);
		free_and_quit("Map not found", data);
	}
	if (!find_map_info(data, flat, beg))
	{
		free (flat);
		free_and_quit("Error: Map, or memory allocation failed", data);
	}
}
