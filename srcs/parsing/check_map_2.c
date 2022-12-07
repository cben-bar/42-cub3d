/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:36:57 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 09:40:43 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_wrong_charset(char c)
{
	if (c == '1' || c == 'X')
		return (0);
	return (1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_just_one_player(char **map, t_data *data)
{
	int	line;
	int	i;
	int	p;

	line = 0;
	i = 0;
	p = 0;
	while (map[line])
	{
		while (map[line][i])
		{
			if (is_player(map[line][i]))
				p++;
			i++;
		}
		line++;
		i = 0;
	}
	if (p == 0)
		free_and_quit("One player is needed at least", data);
	else if (p > 1)
		free_and_quit("Just one player is needed", data);
}

void	fill_data_player(char c, t_data *data, int line, int i)
{
	if (c == 'N')
	{
		data->pov.dir_angle = 90;
		data->pov.quadrant = SECOND_Q;
	}
	if (c == 'S')
	{
		data->pov.dir_angle = 270;
		data->pov.quadrant = FORTH_Q;
	}
	if (c == 'E')
	{
		data->pov.dir_angle = 180;
		data->pov.quadrant = FIRST_Q;
	}
	if (c == 'W')
	{
		data->pov.dir_angle = 0;
		data->pov.quadrant = THIRD_Q;
	}
	data->pov.fcoo.fy = line;
	data->pov.fcoo.fx = i;
	data->pov.fcoo.fy += 0.51;
	data->pov.fcoo.fx += 0.51;
	data->pars->witness_player = 1;
}

void	get_player_pos(char **map, t_data *data)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (map[line])
	{
		while (map[line][i])
		{
			if (is_player(map[line][i]))
				fill_data_player(map[line][i], data, line, i);
			i++;
		}
		line++;
		i = 0;
	}
}
