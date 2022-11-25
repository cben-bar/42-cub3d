/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:45:38 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/25 13:16:28 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

double	get_angle(int angle_to_x)
{
	double radiant;

	radiant = angle_to_x * 0.0174532925;
	if (radiant < M_PI_2)
		return (radiant);
	else if (radiant < M_PI)
		return ((0.0174532925) * (180 - angle_to_x));
	else if (radiant < M_PI * 1.5)
		return (0.0174532925 * (angle_to_x - 180));
	else if (radiant <= M_PI * 2)
		return (0.0174532925 * (90 - (angle_to_x - 270)));
	return (radiant);
}

void	shift_angle(t_data *data, int keycode)
{
	if (keycode == E)
	{
		if (data->pov.direction_angle < 360)
			data->pov.direction_angle += ROTATION;
		if (data->pov.direction_angle >= 360)
			data->pov.direction_angle = 0;	
	}
	if (keycode == Q)
	{
		if (data->pov.direction_angle > 0)
			data->pov.direction_angle -= ROTATION;
		else if (data->pov.direction_angle <= 0)
			data->pov.direction_angle = 360 - ROTATION;	
	}
	if (data->pov.direction_angle >= 0 && data->pov.direction_angle < 90)
		data->pov.quadrant = FIRST_Q;
	else if (data->pov.direction_angle >= 90 && data->pov.direction_angle < 180)
		data->pov.quadrant = SECOND_Q;
	else if (data->pov.direction_angle >= 180 && data->pov.direction_angle < 270)
		data->pov.quadrant = THIRD_Q;
	else if (data->pov.direction_angle >= 270 && data->pov.direction_angle < 360)
		data->pov.quadrant = FORTH_Q;
}

