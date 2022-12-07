/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_to_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:11:30 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 20:18:30 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	north_south(t_data *data, t_img *fov, int x, int y)
{
	int		tx;
	int		ty;
	double	cell_x;

	cell_x = data->pov.next_wall.direction.fx
		- floor(data->pov.next_wall.direction.fx);
	if (data->pov.wall_type == NORTH)
	{
		ty = fabs((HALF_SCREEN - (data->pov.wall_height * 0.5)) - y)
			* (data->wall[0].height / data->pov.wall_height);
		tx = data->wall[0].width * cell_x;
		pixel_put(fov, x, y, get_text_pixel(data->wall[0], tx, ty));
	}
	else if (data->pov.wall_type == SOUTH)
	{
		ty = fabs((HALF_SCREEN - (data->pov.wall_height * 0.5)) - y)
			* (data->wall[1].height / data->pov.wall_height);
		tx = data->wall[1].width * cell_x;
		pixel_put(fov, x, y, get_text_pixel(data->wall[1], tx, ty));
	}
}

static void	east_west(t_data *data, t_img *fov, int x, int y)
{
	int		tx;
	int		ty;
	double	cell_x;

	cell_x = data->pov.next_wall.direction.fy
		- floor(data->pov.next_wall.direction.fy);
	if (data->pov.wall_type == EAST)
	{
		ty = fabs((HALF_SCREEN - (data->pov.wall_height * 0.5)) - y)
			* (data->wall[2].height / data->pov.wall_height);
		tx = data->wall[2].width * cell_x;
		pixel_put(fov, x, y, get_text_pixel(data->wall[2], tx, ty));
	}
	else if (data->pov.wall_type == WEST)
	{
		ty = fabs((HALF_SCREEN - (data->pov.wall_height * 0.5)) - y)
			* (data->wall[3].height / data->pov.wall_height);
		tx = data->wall[3].width * cell_x;
		pixel_put(fov, x, y, get_text_pixel(data->wall[3], tx, ty));
	}	
}

void	pttw(t_data *data, t_img *fov, int x, int y)
{
	north_south(data, fov, x, y);
	east_west(data, fov, x, y);
}
