/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:47:49 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/25 14:29:07 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_bool out_of_bounds(t_data *data, t_fcoo fcoo)
{
	if (fcoo.fx < 0 || fcoo.fx > data->pars->len_map)
		return (true);
	if (fcoo.fy < 0 || fcoo.fy > data->pars->height_map - 1)
		return (true);
	return (false);
}

void	rotate_left(t_data *data, int keycode)
{
	shift_angle(data, keycode);
	mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);
	ft_actualyzer(data);
	// if ((get_next_horizontal_line(data, &data->pov.d_vector_y, data->pov.fcoo) == false)
	// || (get_next_vertical_line(data, &data->pov.d_vector_x, data->pov.fcoo) == false))
	// 	cardinal_value_handler(data, &data->pov.d_vector_x, &data->pov.d_vector_y);

	// mlx_destroy_image(data->mlx, data->map_img.ptr);
	// data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	// data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	// &data->map_img.line_size, &data->map_img.endian);
	
	// draw_map(data, &data->map_img, data->pars->map);
	// vector_to_wall(data);
	// if (((hypothenus(&data->pov.d_vector_x) <= hypothenus(&data->pov.d_vector_y))
	// && (data->pov.direction_angle != 90 && data->pov.direction_angle != 270))
	// || (data->pov.direction_angle == 0 || data->pov.direction_angle == 180))
	// 	dda(data, &data->map_img, data->pov.d_vector_x, GREEN);
	// else if ((hypothenus(&data->pov.d_vector_x) >= hypothenus(&data->pov.d_vector_y))
	// || (data->pov.direction_angle == 90 || data->pov.direction_angle == 270))
	// 	dda(data, &data->map_img, data->pov.d_vector_y, YELLOW);
	// mlx_put_image_to_window(data->mlx, data->win, data->map_img.ptr, 0, 0);
}

void	rotate_right(t_data *data, int keycode)
{
	shift_angle(data, keycode);
	mlx_destroy_image(data->mlx, data->map_img.ptr);
	data->map_img.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->map_img.addr = mlx_get_data_addr(data->map_img.ptr, &data->map_img.bits,
	&data->map_img.line_size, &data->map_img.endian);
	ft_actualyzer(data);
	// if ((get_next_horizontal_line(data, &data->pov.d_vector_y, data->pov.fcoo) == false)
	// || (get_next_vertical_line(data, &data->pov.d_vector_x, data->pov.fcoo) == false))
	// 	cardinal_value_handler(data, &data->pov.d_vector_x, &data->pov.d_vector_y);


	// draw_map(data, &data->map_img, data->pars->map);
	// vector_to_wall(data);
	// if (((hypothenus(&data->pov.d_vector_x) <= hypothenus(&data->pov.d_vector_y))
	// && (data->pov.direction_angle != 90 && data->pov.direction_angle != 270))
	// || (data->pov.direction_angle == 0 || data->pov.direction_angle == 180))
	// 	dda(data, &data->map_img, data->pov.d_vector_x, GREEN);
	// else if ((hypothenus(&data->pov.d_vector_x) >= hypothenus(&data->pov.d_vector_y))
	// || (data->pov.direction_angle == 90 || data->pov.direction_angle == 270))
	// 	dda(data, &data->map_img, data->pov.d_vector_y, YELLOW);
	// mlx_put_image_to_window(data->mlx, data->win, data->map_img.ptr, 0, 0);
}
