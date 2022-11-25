/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:59:17 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/16 17:24:48 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_forbidden(char c)
{
	if (c == 'X')
		return (1);
	return (0);
}

void	check_arround(char **map, int i, int line, t_data *data)
{
	if (map[line][i -1])
	{
		if (is_forbidden(map[line][i - 1]))
			free_and_quit("Invalid map", data);
	}
	if (map[line][i + 1])
	{
		if (is_forbidden(map[line][i + 1]))
			free_and_quit("Invalid map", data);
	}
	if (line -1 >= 0)
	{
		if (is_forbidden(map[line - 1][i]))
			free_and_quit("Invalid map", data);
	}
	if (map[line + 1])
	{
		if (is_forbidden(map[line + 1][i]))
			free_and_quit("Invalid map", data);
	}
}

void	cross_check(char **map, t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == '0' || map[line][i] == 'N'
				|| map[line][i] == 'S' || map[line][i] == 'E'
				|| map[line][i] == 'W')
				check_arround(map, i, line, data);
			i++;
		}
		line++;
	}
}
