/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:25 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 21:09:12 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	failsafe(t_data *data, int *x, int *y)
{
	if (*x < 0)
		*x = 0;
	else if (*x > data->pars->len_map)
		*x = data->pars->len_map;
	if (*y < 0)
		*y = 0;
	else if (*y > data->pars->height_map - 1)
		*y = data->pars->height_map - 1;
}

t_bool	is_it_a_vertical_wall_daddy(t_data *data, t_vector vector_x)
{
	int	x;
	int	y;

	x = (int)vector_x.direction.fx;
	y = (int)vector_x.direction.fy;
	failsafe(data, &x, &y);
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == FORTH_Q)
	{
		if ((int)vector_x.direction.fx == vector_x.direction.fx
			&& (int)vector_x.direction.fy == vector_x.direction.fy
			&& x > 0 && y > 0 && (data->pars->map[y - 1][x - 1]) == '1')
			return (true);
		else if ((x > 0 && data->pars->map[y][x - 1] == '1')
		|| (x == 0 && data->pars->map[y][x] == '1'))
			return (true);
	}
	else
	{
		if (((int)vector_x.direction.fx == vector_x.direction.fx
				&& (int)vector_x.direction.fy == vector_x.direction.fy && y > 0
				&& (data->pars->map[y - 1][x]) == '1')
			|| (data->pars->map[y][x] == '1'))
			return (true);
	}
	return (false);
}

t_bool	is_it_a_horizontal_wall_daddy(t_data *data, t_vector vector_y)
{
	int	x;
	int	y;

	x = (int)vector_y.direction.fx;
	y = (int)vector_y.direction.fy;
	failsafe(data, &x, &y);
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
	{
		if (y > 0 && data->pars->map[y - 1][x] == '1')
			return (true);
		else if (y == 0 && data->pars->map[y][x] == '1')
			return (true);
	}
	else
	{
		if ((int)vector_y.direction.fx == vector_y.direction.fx
			&& (int)vector_y.direction.fy == vector_y.direction.fy && y > 0
			&& (data->pars->map[y - 1][x]) == '1')
			return (true);
		if (data->pars->map[y][x] == '1')
			return (true);
	}
	return (false);
}
