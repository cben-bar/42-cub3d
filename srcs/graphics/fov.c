/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:36:05 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 14:19:21 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	set_wall_type_h(t_data *data)
{
	if (data->pov.quadrant == FIRST_Q)
		data->pov.wall_type = NORTH;
	else if (data->pov.quadrant == SECOND_Q)
		data->pov.wall_type = NORTH;
	else if (data->pov.quadrant == THIRD_Q)
		data->pov.wall_type = SOUTH;
	else if (data->pov.quadrant == FORTH_Q)
		data->pov.wall_type = SOUTH;
}

static void	set_wall_type_v(t_data *data)
{
	if (data->pov.quadrant == FIRST_Q)
		data->pov.wall_type = WEST;
	else if (data->pov.quadrant == SECOND_Q)
		data->pov.wall_type = EAST;
	else if (data->pov.quadrant == THIRD_Q)
		data->pov.wall_type = EAST;
	else if (data->pov.quadrant == FORTH_Q)
		data->pov.wall_type = WEST;
}

static void	vector_actualyser(t_data *data)
{
	if ((get_next_horizontal_line(data, &data->pov.vector_y, data->pov.fcoo)
			== false)
		| (get_next_vertical_line(data, &data->pov.vector_x, data->pov.fcoo)
			== false))
	{
		cardinal_value_handler(data, &data->pov.vector_x, &data->pov.vector_y);
		return ;
	}
	vector_to_wall(data);
	if (((hypothenus(&data->pov.vector_x)
				< hypothenus(&data->pov.vector_y))
			&& (data->pov.dir_angle != 90 && data->pov.dir_angle != 270))
		|| (data->pov.dir_angle == 0 || data->pov.dir_angle == 180))
	{
		set_wall_type_v(data);
		data->pov.next_wall = data->pov.vector_x;
	}
	else if ((hypothenus(&data->pov.vector_x) > hypothenus(&data->pov.vector_y))
		|| (data->pov.dir_angle == 90 || data->pov.dir_angle == 270))
	{
		set_wall_type_h(data);
		data->pov.next_wall = data->pov.vector_y;
	}
	else
		data->pov.next_wall = data->pov.vector_y;
}

static void	adjust_angle(t_data *data)
{
	if (data->pov.dir_angle < 0)
		data->pov.dir_angle += 360.0;
	else if (data->pov.dir_angle >= 360)
		data->pov.dir_angle -= 360.0;
}

void	fov(t_data *data)
{
	double	angle_buff;
	int		angle_shift;
	double	new_angle;

	angle_buff = data->pov.dir_angle;
	angle_shift = 0;
	if (data->pov.dir_angle + HALF_FOV >= 360)
		data->pov.dir_angle = data->pov.dir_angle + HALF_FOV - 360;
	else
		data->pov.dir_angle = data->pov.dir_angle + HALF_FOV;
	while (angle_shift < RAY_NB)
	{
		angle_shift ++;
		change_quadrant(data);
		vector_actualyser(data);
		new_angle = calculate_angle_shifter(angle_shift) * (180 / PI);
		data->pov.dir_angle = angle_buff + HALF_FOV - new_angle;
		adjust_angle(data);
		dda(data, &data->map_img, data->pov.next_wall, GREEN);
		put_fov_to_screen(data, &data->pov.next_wall, new_angle, angle_shift);
	}
	data->pov.dir_angle = angle_buff;
	change_quadrant(data);
}
