/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:49:02 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/25 15:38:03 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void 	draw_line (t_data *data, double angle, int side)
{
	double	x_line;
	double	y_line;
	int		ray_lenght;
	int		i;

	x_line = 0;
	y_line = 0;
	ray_lenght = 100; //valeur a definir par le detecteur de collisions
	i = 0;

	if (side == RIGHT)
	{
		while (i < ray_lenght)
		{
			if ((data->pov.fcoo.fx *  MAP_SQUARE + x_line < 0 || data->pov.fcoo.fy *  MAP_SQUARE + y_line < 0)
			|| (data->pov.fcoo.fx *  MAP_SQUARE + x_line > WIN_W || data->pov.fcoo.fy *  MAP_SQUARE + y_line > WIN_H))
				break ;
			pixel_put(&data->map_img, ((data->pov.fcoo.fx * MAP_SQUARE) + x_line), ((data->pov.fcoo.fy * MAP_SQUARE) + y_line), MAGENTA);
			x_line += -1 * cos(angle);
			y_line += sin(angle);
			i++;
		}
	}
	else if (side == LEFT)
		{
		while (i < ray_lenght)
		{
			if ((data->pov.fcoo.fx *  MAP_SQUARE + x_line < 0 || data->pov.fcoo.fy *  MAP_SQUARE + y_line < 0)
			|| (data->pov.fcoo.fx *  MAP_SQUARE + x_line > WIN_W || data->pov.fcoo.fy *  MAP_SQUARE + y_line > WIN_H))
				break ;
			pixel_put(&data->map_img, ((data->pov.fcoo.fx * MAP_SQUARE) + x_line), ((data->pov.fcoo.fy * MAP_SQUARE) + y_line), MAGENTA);
			x_line -= cos(angle);
			y_line -= -1 * sin(angle);
			i++;
		}
	}
}

void	set_fov(t_data *data)
{
	int		i;
	double	angle;
	int		val;
	
	i = 0;
	val = -data->pov.direction_angle;
	while (i < 30)
	{
		angle = get_angle(val);
		draw_line(data, angle, RIGHT);
		val = val % 360;
		val += 2;
		i++;
	}
	i = 0;
	val = -data->pov.direction_angle;
	while (i < 30)
	{
		angle = get_angle(val);
		draw_line(data, angle, LEFT);
		val = val % 360;
		val -= 2;
		i++;
	}
}

void	ft_actualyzer(t_data *data)
{
	if ((get_next_horizontal_line(data, &data->pov.d_vector_y, data->pov.fcoo) == false)
	|| (get_next_vertical_line(data, &data->pov.d_vector_x, data->pov.fcoo) == false))
		cardinal_value_handler(data, &data->pov.d_vector_x, &data->pov.d_vector_y);

	draw_map(data, &data->map_img, data->pars->map);
	vector_to_wall(data);
	if (((hypothenus(&data->pov.d_vector_x) <= hypothenus(&data->pov.d_vector_y))
	&& (data->pov.direction_angle != 90 && data->pov.direction_angle != 270))
	|| (data->pov.direction_angle == 0 || data->pov.direction_angle == 180))
		dda(data, &data->map_img, data->pov.d_vector_x, GREEN);
	else if ((hypothenus(&data->pov.d_vector_x) >= hypothenus(&data->pov.d_vector_y))
	|| (data->pov.direction_angle == 90 || data->pov.direction_angle == 270))
		dda(data, &data->map_img, data->pov.d_vector_y, YELLOW);
	set_fov(data);
	mlx_put_image_to_window(data->mlx, data->win, data->map_img.ptr, 0, 0);
}

void	move_forward(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);

	if (data->pov.quadrant == FIRST_Q)
	{
		data->pov.fcoo.fx -= STEP * cos(get_angle(data->pov.direction_angle));
		data->pov.fcoo.fy -= STEP * sin(get_angle(data->pov.direction_angle));
	}
	else if (data->pov.quadrant == SECOND_Q)
	{
		data->pov.fcoo.fx += STEP * (cos(get_angle(data->pov.direction_angle)));
		data->pov.fcoo.fy -= STEP * (sin(get_angle(data->pov.direction_angle)));
	}
	else if (data->pov.quadrant == THIRD_Q)
	{
		data->pov.fcoo.fx += STEP * cos(get_angle(data->pov.direction_angle));
		data->pov.fcoo.fy += STEP * sin(get_angle(data->pov.direction_angle));
	}
	else if (data->pov.quadrant == FORTH_Q)
	{
		data->pov.fcoo.fx -= STEP * (cos(get_angle(data->pov.direction_angle)));
		data->pov.fcoo.fy += STEP * (sin(get_angle(data->pov.direction_angle)));
	}
	ft_actualyzer(data);
}

void	move_backward(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);

	if (data->pov.quadrant == FIRST_Q)
	{
		data->pov.fcoo.fx += STEP * cos(get_angle(data->pov.direction_angle));
		data->pov.fcoo.fy += STEP * sin(get_angle(data->pov.direction_angle));
	}
	else if (data->pov.quadrant == SECOND_Q)
	{
		data->pov.fcoo.fx -= STEP * (cos(get_angle(data->pov.direction_angle)));
		data->pov.fcoo.fy += STEP * (sin(get_angle(data->pov.direction_angle)));
	}
	else if (data->pov.quadrant == THIRD_Q)
	{
		data->pov.fcoo.fx -= STEP * cos(get_angle(data->pov.direction_angle));
		data->pov.fcoo.fy -= STEP * sin(get_angle(data->pov.direction_angle));
	}
	else if (data->pov.quadrant == FORTH_Q)
	{
		data->pov.fcoo.fx += STEP * (cos(get_angle(data->pov.direction_angle)));
		data->pov.fcoo.fy -= STEP * (sin(get_angle(data->pov.direction_angle)));
	}
	ft_actualyzer(data);
}

void	move_right(t_data *data)
{
	float	x1;
	float	y1;
	float	tmp_x1;

	// mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);

	if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
		x1 = STEP * cos(get_angle(data->pov.direction_angle));
	else
		x1 = STEP * (-1 * cos(get_angle(data->pov.direction_angle)));
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
		y1 = STEP * sin(-get_angle(data->pov.direction_angle));
	else
		y1 = STEP * sin(get_angle(data->pov.direction_angle));
	tmp_x1 = x1;
	x1 = cos(1.570796) * x1 - sin(1.570796) * y1;
	y1 = sin(1.570796) * tmp_x1 + cos(1.570796) * y1;
	data->pov.fcoo.fx += x1;
	data->pov.fcoo.fy += y1;
	ft_actualyzer(data);
}

void	move_left(t_data *data)
{
	float	x1;
	float	y1;
	float	tmp_x1;
	// mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);

	if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
		x1 = STEP * (1 * cos(get_angle(data->pov.direction_angle)));
	else
		x1 = STEP * (-1 * cos(get_angle(data->pov.direction_angle)));
	if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
		y1 = STEP * sin(-get_angle(data->pov.direction_angle));
	else
		y1 = STEP * sin(get_angle(data->pov.direction_angle));
	tmp_x1 = x1;
	x1 = cos(1.570796) * x1 - sin(-1.570796) * y1;
	y1 = sin(-1.570796) * tmp_x1 + cos(1.570796) * y1;
	data->pov.fcoo.fx += x1;
	data->pov.fcoo.fy += y1;
	ft_actualyzer(data);
}
