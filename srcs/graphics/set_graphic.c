/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:53:20 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:02:04 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	set_colors(t_data *data)
{
	data->floor_color = data->pars->floor[0] * (256 * 256)
		+ 256 * data->pars->floor[1] + data->pars->floor[2];
	data->ceilling_color = data->pars->ceilling[0] * (256 * 256)
		+ 256 * data->pars->ceilling[1] + data->pars->ceilling[2];
}

void	xpm_to_images_2(t_data *data)
{
	if (data->wall[2].ptr == NULL)
		ft_exit (data);
	data->wall[2].addr = mlx_get_data_addr(data->wall[2].ptr,
			&data->wall[2].bits, &data->wall[2].line_size,
			&data->wall[2].endian);
	data->wall[3].ptr = mlx_xpm_file_to_image(data->mlx,
			data->pars->we, &data->wall[3].width, &data->wall[3].height);
	if (data->wall[3].ptr == NULL)
		ft_exit (data);
	data->wall[3].addr = mlx_get_data_addr(data->wall[3].ptr,
			&data->wall[3].bits, &data->wall[3].line_size,
			&data->wall[3].endian);
}

void	xpm_to_images(t_data *data)
{
	data->wall[0].ptr = mlx_xpm_file_to_image(data->mlx,
			data->pars->no, &data->wall[0].width, &data->wall[0].height);
	if (data->wall[0].ptr == NULL)
		ft_exit (data);
	data->wall[0].addr = mlx_get_data_addr(data->wall[0].ptr,
			&data->wall[0].bits, &data->wall[0].line_size,
			&data->wall[0].endian);
	data->wall[1].ptr = mlx_xpm_file_to_image(data->mlx,
			data->pars->so, &data->wall[1].width, &data->wall[1].height);
	if (data->wall[1].ptr == NULL)
		ft_exit (data);
	data->wall[1].addr = mlx_get_data_addr(data->wall[1].ptr,
			&data->wall[1].bits, &data->wall[1].line_size,
			&data->wall[1].endian);
	data->wall[2].ptr = mlx_xpm_file_to_image(data->mlx,
			data->pars->ea, &data->wall[2].width, &data->wall[2].height);
	xpm_to_images_2(data);
}

void	minimap_size_init(t_data *data)
{
	if (data->pars->len_map > 24)
		data->map_img.width = 24;
	else
		data->map_img.width = data->pars->len_map;
	if (data->pars->height_map > 24)
		data->map_img.height = 24;
	else
		data->map_img.height = data->pars->height_map - 1;
}
