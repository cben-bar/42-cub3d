/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:02:07 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 14:01:34 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	line_coo_modification(t_data data,
	t_vector vector, float *x, float *y)
{
	if (data.pov.dir_angle >= 0 && data.pov.dir_angle < 90)
	{
		*x = *x - vector.dx;
		*y = *y - vector.dy;
	}
	else if (data.pov.dir_angle >= 90 && data.pov.dir_angle < 180)
	{
		*x = *x + vector.dx;
		*y = *y - vector.dy;
	}
	else if (data.pov.dir_angle >= 180 && data.pov.dir_angle < 270)
	{
		*x = *x + vector.dx;
		*y = *y + vector.dy;
	}
	else if (data.pov.dir_angle >= 270 && data.pov.dir_angle < 360)
	{
		*x = *x - vector.dx;
		*y = *y + vector.dy;
	}
}

void	dda(t_data *data, t_img *img, t_vector vector, int color)
{
	int		i;
	float	x;
	float	y;
	float	step;

	x = vector.start.fx * MAP_SQUARE;
	y = vector.start.fy * MAP_SQUARE;
	vector.dx = fabsf((vector.direction.fx * MAP_SQUARE) - x);
	vector.dy = fabsf((vector.direction.fy * MAP_SQUARE) - y);
	i = 1;
	if (vector.dx >= vector.dy)
		step = vector.dx;
	else
		step = vector.dy;
	vector.dx = vector.dx / step;
	vector.dy = vector.dy / step;
	while (i <= step + 1)
	{
		if ((x < 0 || x >= WIN_W - MAP_SQUARE * data->map_img.width + 1)
			|| (y < 0 || y >= WIN_H - MAP_SQUARE * data->map_img.height))
			break ;
		pixel_put(img, x, y, color);
		line_coo_modification(*data, vector, &x, &y);
		i ++;
	}
}
