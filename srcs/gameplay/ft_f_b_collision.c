/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_b_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:17:11 by beni              #+#    #+#             */
/*   Updated: 2022/12/07 10:07:59 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_bool	f_first_quadrant(t_data *data)
{
	double	tmp_x;
	double	tmp_y;
	int		x1;
	int		y1;

	tmp_x = data->pov.fcoo.fx;
	x1 = (int)floor(tmp_x);
	tmp_x -= STEP * cos(get_angle(data->pov.dir_angle));
	tmp_y = data->pov.fcoo.fy;
	y1 = (int)floor(tmp_y);
	tmp_y -= STEP * sin(get_angle(data->pov.dir_angle));
	if (data->pars->map[(int)ceil(tmp_y) - 1][(int)ceil(tmp_x) - 1])
	{
		if (data->pars->map[(int)ceil(tmp_y) - 1][(int)ceil(tmp_x) - 1] == '1'
			|| data->pars->map[(int)ceil(tmp_y) - 1]
			[(int)ceil(tmp_x) - 1] == 'X')
			return (true);
	}
	if (((int)floor(tmp_x) != x1) || ((int)floor(tmp_y) != y1))
	{
		if (data->pars->map[y1 - 1][x1] == '1'
			&& data->pars->map[y1][x1 - 1] == '1')
			return (true);
	}
	return (false);
}

t_bool	f_second_quadrant(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->pov.fcoo.fx;
	tmp_x += STEP * cos(get_angle(data->pov.dir_angle));
	tmp_y = data->pov.fcoo.fy;
	tmp_y -= STEP * sin(get_angle(data->pov.dir_angle));
	if (data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)])
	{
		if (data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)] == '1'
			|| data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)] == 'X')
			return (true);
	}
	return (false);
}

t_bool	f_third_quadrant(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->pov.fcoo.fx;
	tmp_x += STEP * cos(get_angle(data->pov.dir_angle));
	tmp_y = data->pov.fcoo.fy;
	tmp_y += STEP * sin(get_angle(data->pov.dir_angle));
	if (data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)])
	{
		if (data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)] == '1'
			|| data->pars->map[(int)floor(tmp_y)][(int)floor(tmp_x)] == 'X')
			return (true);
	}
	return (false);
}

t_bool	f_forth_quadrant(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->pov.fcoo.fx;
	tmp_x -= STEP * cos(get_angle(data->pov.dir_angle));
	tmp_y = data->pov.fcoo.fy;
	tmp_y += STEP * sin(get_angle(data->pov.dir_angle));
	if (data->pars->map[(int)floor(tmp_y)][(int)ceil(tmp_x) - 1])
	{
		if (data->pars->map[(int)floor(tmp_y)][(int)ceil(tmp_x) - 1] == '1'
			|| data->pars->map[(int)floor(tmp_y)][(int)ceil(tmp_x) - 1] == 'X')
			return (true);
	}
	return (false);
}

t_bool	this_is_f_b_collision(t_data *data, int direction)
{
	if ((data->pov.quadrant == FIRST_Q && direction == FORWARD)
		|| (data->pov.quadrant == THIRD_Q && direction == BACKWARD))
	{
		if (f_first_quadrant(data))
			return (true);
	}
	if ((data->pov.quadrant == SECOND_Q && direction == FORWARD)
		|| (data->pov.quadrant == FORTH_Q && direction == BACKWARD))
	{
		if (f_second_quadrant(data))
			return (true);
	}
	if ((data->pov.quadrant == THIRD_Q && direction == FORWARD)
		|| (data->pov.quadrant == FIRST_Q && direction == BACKWARD))
	{
		if (f_third_quadrant(data))
			return (true);
	}
	if ((data->pov.quadrant == FORTH_Q && direction == FORWARD)
		|| (data->pov.quadrant == SECOND_Q && direction == BACKWARD))
	{
		if (f_forth_quadrant(data))
			return (true);
	}
	return (false);
}
