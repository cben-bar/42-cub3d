/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:05:38 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/07 13:39:43 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	draw_floor_n_ceilling(
t_data *data, t_img *fov, double wall_h, int angle_shift)
{
	int		y;
	double	wall_top;
	double	wall_bot;

	wall_top = HALF_SCREEN - (wall_h * 0.5);
	wall_bot = HALF_SCREEN + (wall_h * 0.5);
	y = 0;
	while (y < HALF_SCREEN)
	{
		if (y > wall_top)
			pttw(data, fov, WIN_W - angle_shift, y);
		else
			pixel_put(fov, WIN_W - angle_shift, y, data->ceilling_color);
		y ++;
	}
	while (y < WIN_H)
	{
		if (y < wall_bot)
			pttw(data, fov, WIN_W - angle_shift, y);
		else
			pixel_put(fov, WIN_W - angle_shift, y, data->floor_color);
		y ++;
	}
}

double	calculate_angle_shifter(int angle_shifts)
{
	double	a;
	double	b;
	double	c;
	double	angle_shifter;

	(void) angle_shifts;
	a = (WIN_W * 0.5) / cos(M_PI_4);
	b = angle_shifts;
	c = sqrt(a * a + b * b - (2 * a * b * cos(M_PI_4)));
	angle_shifter = acos((a * a + c * c - b * b) / (2 * a * c));
	return (angle_shifter);
}

void	put_fov_to_screen(
t_data *data, t_vector *next_wall, double angle, int angle_shift)
{
	(void) data;
	next_wall->length
		= sin(get_angle(FOV - fabs(HALF_FOV - angle)))
		* hypothenus(next_wall);
	data->pov.wall_height = WIN_H / (next_wall->length);
	draw_floor_n_ceilling(data, &data->fov, data->pov.wall_height, angle_shift);
}
