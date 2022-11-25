/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:37 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/16 17:26:40 by cben-bar         ###   ########lyon.fr   */
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
	fill_struct(data, flat, i);
	return (1);
}

int	check_just_map(char *flat)
{
	int	i;
	int	check;
	int	nl;

	i = 0;
	while (flat[i])
	{
		check = is_in_charset(flat[i]);
		nl = new_line_counter(&flat[i]);
		if (flat[i] != '\n')
			if (check == 0 || nl == 0)
				return (0);
		i++;
	}
	return (1);
}

int	find_beg_map(char *flat, int i)
{
	int	j;
	int	check;
	int	v;

	j = i;
	check = 0;
	while (flat[j] && check == 0)
	{
		while (flat[j] == '\n')
			j++;
		i = j;
		check = 1;
		while (flat[j] && flat[j] != '\n')
		{
			v = is_in_charset(flat[j]);
			if (v != 1 && v != 3)
				check = 0;
			j++;
			if (!check_just_map(&flat[i]))
				check = 0;
		}
	}
	if ((size_t)j == ft_strlen(flat))
		return (j);
	return (i);
}

void	find_map(char *flat, t_data *data)
{
	int	i;

	i = find_beg_map(flat, 0);
	if ((size_t)i == ft_strlen(flat))
	{
		free(flat);
		free_and_quit("Map not found", data);
	}
	if (!find_map_info(data, flat, i))
		free_and_quit("Error: Map, or memory allocation failed", data);
}
