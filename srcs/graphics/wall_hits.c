/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:25 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/25 14:06:13 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void vertical(t_data *data)
{
	if ((is_it_a_vertical_wall_daddy(data, data->pov.d_vector_x) == true)
	|| (data->pov.direction_angle == 90 ||  data->pov.direction_angle == 270))
			return ;
	while (out_of_bounds(data, data->pov.d_vector_x.direction) == false)
	{
		if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
			data->pov.d_vector_x.direction.fy -= data->pov.d_vector_x.step_y;
		else
			data->pov.d_vector_x.direction.fy += data->pov.d_vector_x.step_y;
		if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
			data->pov.d_vector_x.direction.fx += 1;
		else
			data->pov.d_vector_x.direction.fx -= 1;
		if (is_it_a_vertical_wall_daddy(data, data->pov.d_vector_x) == true)
			break;
	}
}

void horizontal(t_data *data)
{
	if ((is_it_a_horizontal_wall_daddy(data, data->pov.d_vector_y) == true)
	|| (data->pov.direction_angle == 0 || data->pov.direction_angle == 180))
		return;
	while (out_of_bounds(data, data->pov.d_vector_y.direction) == false)
	{
		if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
			data->pov.d_vector_y.direction.fx += data->pov.d_vector_y.step_x;
		else
			data->pov.d_vector_y.direction.fx -= data->pov.d_vector_y.step_x;
		if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
			data->pov.d_vector_y.direction.fy -= 1;
		else
			data->pov.d_vector_y.direction.fy += 1;
		if (is_it_a_horizontal_wall_daddy(data, data->pov.d_vector_y) == true)
			break ;
	}
}

void	vector_to_wall(t_data *data)
{
	get_vector_step(data, &data->pov.d_vector_x, X);
	get_vector_step(data, &data->pov.d_vector_y, Y);
	vertical(data);
	horizontal(data);
}

t_bool	is_it_a_vertical_wall_daddy(t_data *data, t_vector vector_x)
{
	int x;
	int y;
	x = (int)vector_x.direction.fx;
	y = (int)vector_x.direction.fy;
	if (x < 0)
		x = 0;
	else if (x > data->pars->len_map)
		x = data->pars->len_map;
	if (y < 0)
		y = 0;
	else if (y > data->pars->height_map - 1)
		y = data->pars->height_map - 1;
	// printf("V x f = %f, yf = %f\n", vector_x.direction.fx,vector_x.direction.fy);
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == FORTH_Q)
	{
		// pixel_put(&data->map_img, vector_x.direction.fx * MAP_SQUARE, vector_x.direction.fy * MAP_SQUARE, RED);
		if (x > 0 && data->pars->map[y][x - 1] == '1')
		{
			// printf("1 V map[%d][%d] = %c\n", y, x, data->pars->map[y][x]);
			return (true);
		}
		else if (x == 0 && data->pars->map[y][x] == '1')
		{
			// printf("2 V map[%d][%d] = %c\n", y, x, data->pars->map[y][x]);
			return (true);
		}
	}
	else
	{
		// pixel_put(&data->map_img, vector_x.direction.fx * MAP_SQUARE, vector_x.direction.fy * MAP_SQUARE, RED);
		if (data->pars->map[y][x] == '1')
		{
			// printf("3 V map[%d][%d] = %c\n", y, x, data->pars->map[y][x]);
			return (true);
		}
	}
	// printf("4 V map[%d][%d] = %c\n", y, x, data->pars->map[y][x]);
	return (false);
}

t_bool	is_it_a_horizontal_wall_daddy(t_data *data, t_vector vector_y)
{
	int x;
	int y;
	x = (int)vector_y.direction.fx;
	y = (int)vector_y.direction.fy;
	if (x < 0)
		x = 0;
	else if (x > data->pars->len_map)
		x = data->pars->len_map;
	if (y < 0)
		y = 0;
	else if (y > data->pars->height_map - 1)
		y = data->pars->height_map - 1;
	// printf("H x f = %f, yf = %f\n", vector_y.direction.fx,vector_y.direction.fy);
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
	{
		if (y > 0 && data->pars->map[y - 1][x] == '1')
		{
			// printf("1 H map[%d][%d] = %c\n", y - 1, x, data->pars->map[y - 1][x]);
			return (true);
		}
		else if (y == 0 && data->pars->map[y][x] == '1')
			return (true);
	}
	else
	{
		if (data->pars->map[y][x] == '1')
		{
			// printf("2 H map[%d][%d] = %c\n", y, x, data->pars->map[y][x]);
			return (true);
		}
	}
	// printf("ange = %d 3 H map[%d][%d] = %c\n", data->pov.direction_angle, y, x, data->pars->map[y][x]);
	return (false);
}
