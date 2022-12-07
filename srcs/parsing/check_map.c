/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:41:42 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 09:50:15 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_first_last(char **map, t_data *data)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (map[line][i])
	{
		if (map[line][i] != '1' && map[line][i] != 'X')
			free_and_quit("Invalid map", data);
		i++;
	}
	line = data->pars->height_map - 1;
	i = 0;
	while (map[line][i])
	{
		if (map[line][i] != '1' && map[line][i] != 'X')
			free_and_quit("Invalid map", data);
		i++;
	}
}

void	check_left_border(char **map, t_data *data)
{
	int	line;
	int	i;
	int	ok_b;

	line = 0;
	i = 0;
	ok_b = 0;
	while (map[line])
	{
		while (map[line][i])
		{
			if (map[line][i] == '1')
				ok_b++;
			else if (is_wrong_charset(map[line][i]) && !ok_b)
				free_and_quit("Invalid map", data);
			i++;
		}
		ok_b = 0;
		i = 0;
		line++;
	}
}

void	check_right_border(char **map, t_data *data)
{
	int	line;
	int	i;
	int	ok_b;

	line = 0;
	i = data->pars->len_map - 1;
	ok_b = 0;
	while (map[line])
	{
		while (i)
		{
			if (map[line][i] == '1')
				ok_b++;
			else if (is_wrong_charset(map[line][i]) && !ok_b)
				free_and_quit("Invalid map", data);
			i--;
		}
		ok_b = 0;
		i = data->pars->len_map - 1;
		line++;
	}
}

void	check_top(char **map, t_data *data)
{
	int	line;
	int	i;
	int	ok_b;

	line = 0;
	i = 0;
	ok_b = 0;
	while (map[line][i])
	{
		while (map[line])
		{
			if (map[line][i] == '1')
				ok_b++;
			else if (is_wrong_charset(map[line][i]) && !ok_b)
				free_and_quit("Invalid map", data);
			line++;
		}
		ok_b = 0;
		line = 0;
		i++;
	}
}

void	check_map(t_data *data)
{
	check_first_last(data->pars->map, data);
	check_left_border(data->pars->map, data);
	check_right_border(data->pars->map, data);
	check_top(data->pars->map, data);
	cross_check(data->pars->map, data);
	check_just_one_player(data->pars->map, data);
	get_player_pos(data->pars->map, data);
}
