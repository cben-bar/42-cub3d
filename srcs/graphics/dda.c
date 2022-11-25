/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:02:07 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:10 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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
	while (i <= step)
	{
		if ((x < 0 || x > WIN_W)
		|| (y < 0 || y > WIN_H))
			break ;
		pixel_put(img, x, y, color);
		if (data->pov.direction_angle >= 0 && data->pov.direction_angle <= 90)
		{
			x = x - vector.dx;	
			y = y - vector.dy;
		}
		else if (data->pov.direction_angle > 90 && data->pov.direction_angle < 180)
		{
			x = x + vector.dx;	
			y = y - vector.dy;	
		}
		else if(data->pov.direction_angle >= 180 && data->pov.direction_angle < 270)
		{
			x = x + vector.dx;	
			y = y + vector.dy;
		}
		else if(data->pov.direction_angle >= 270 && data->pov.direction_angle < 360)
		{
			x = x - vector.dx;
			y = y + vector.dy;
		}
		i ++;
	}
}
