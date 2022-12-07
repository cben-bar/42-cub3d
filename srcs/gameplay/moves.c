/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:49:02 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 09:50:20 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_actualyzer(t_data *data)
{
	data->fov.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->fov.addr = mlx_get_data_addr(data->fov.ptr, &data->fov.bits,
			&data->fov.line_size, &data->fov.endian);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr,
			&data->map_img.bits, &data->map_img.line_size,
			&data->map_img.endian);
	draw_map(&data->map_img, data->pars->map);
	fov(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fov.ptr, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map_img.ptr,
		WIN_W - MAP_SQUARE * (data->map_img.width + 1),
		WIN_H - MAP_SQUARE * (data->map_img.height + 1));
	mlx_destroy_image(data->mlx, data->fov.ptr);
	mlx_destroy_image(data->mlx, data->map_img.ptr);
}

void	move_forward(t_data *data)
{
	if (this_is_f_b_collision(data, FORWARD))
		return ;
	if (data->pov.quadrant == FIRST_Q)
	{
		data->pov.fcoo.fx -= STEP * cos(get_angle(data->pov.dir_angle));
		data->pov.fcoo.fy -= STEP * sin(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.quadrant == SECOND_Q)
	{
		data->pov.fcoo.fx += STEP * (cos(get_angle(data->pov.dir_angle)));
		data->pov.fcoo.fy -= STEP * (sin(get_angle(data->pov.dir_angle)));
	}
	else if (data->pov.quadrant == THIRD_Q)
	{
		data->pov.fcoo.fx += STEP * cos(get_angle(data->pov.dir_angle));
		data->pov.fcoo.fy += STEP * sin(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.quadrant == FORTH_Q)
	{
		data->pov.fcoo.fx -= STEP * (cos(get_angle(data->pov.dir_angle)));
		data->pov.fcoo.fy += STEP * (sin(get_angle(data->pov.dir_angle)));
	}
	ft_actualyzer(data);
}

void	move_backward(t_data *data)
{
	if (this_is_f_b_collision(data, BACKWARD))
		return ;
	if (data->pov.quadrant == FIRST_Q)
	{
		data->pov.fcoo.fx += STEP * cos(get_angle(data->pov.dir_angle));
		data->pov.fcoo.fy += STEP * sin(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.quadrant == SECOND_Q)
	{
		data->pov.fcoo.fx -= STEP * (cos(get_angle(data->pov.dir_angle)));
		data->pov.fcoo.fy += STEP * (sin(get_angle(data->pov.dir_angle)));
	}
	else if (data->pov.quadrant == THIRD_Q)
	{
		data->pov.fcoo.fx -= STEP * cos(get_angle(data->pov.dir_angle));
		data->pov.fcoo.fy -= STEP * sin(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.quadrant == FORTH_Q)
	{
		data->pov.fcoo.fx += STEP * (cos(get_angle(data->pov.dir_angle)));
		data->pov.fcoo.fy -= STEP * (sin(get_angle(data->pov.dir_angle)));
	}
	ft_actualyzer(data);
}

void	move_right(t_data *data)
{
	float	x1;
	float	y1;
	float	tmp_x1;

	if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
		x1 = STEP * cos(get_angle(data->pov.dir_angle));
	else
		x1 = STEP * (-1 * cos(get_angle(data->pov.dir_angle)));
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
		y1 = STEP * sin(-get_angle(data->pov.dir_angle));
	else
		y1 = STEP * sin(get_angle(data->pov.dir_angle));
	tmp_x1 = x1;
	x1 = cos(1.570796) * x1 - sin(1.570796) * y1;
	y1 = sin(1.570796) * tmp_x1 + cos(1.570796) * y1;
	if (this_is_r_l_collision(data, x1, y1))
		return ;
	data->pov.fcoo.fx += x1;
	data->pov.fcoo.fy += y1;
	ft_actualyzer(data);
}

void	move_left(t_data *data)
{
	float	x1;
	float	y1;
	float	tmp_x1;

	if ((data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q))
		x1 = STEP * (1 * cos(get_angle(data->pov.dir_angle)));
	else
		x1 = STEP * (-1 * cos(get_angle(data->pov.dir_angle)));
	if ((data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q))
		y1 = STEP * sin(-get_angle(data->pov.dir_angle));
	else
		y1 = STEP * sin(get_angle(data->pov.dir_angle));
	tmp_x1 = x1;
	x1 = cos(1.570796) * x1 - sin(-1.570796) * y1;
	y1 = sin(-1.570796) * tmp_x1 + cos(1.570796) * y1;
	if (this_is_r_l_collision(data, x1, y1))
		return ;
	data->pov.fcoo.fx += x1;
	data->pov.fcoo.fy += y1;
	ft_actualyzer(data);
}
