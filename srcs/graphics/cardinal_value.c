/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:32 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/02 10:03:23 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	cardinal_value_handler(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{
	vector_x->start.fx = data->pov.fcoo.fx;
	vector_x->start.fy = data->pov.fcoo.fy;
	vector_y->start.fx = data->pov.fcoo.fx;
	vector_y->start.fy = data->pov.fcoo.fy;
	if (data->pov.dir_angle == 90)
	{
		vector_to_wall(data);
		data->pov.next_wall = *vector_y;
	}
	else if (data->pov.dir_angle == 270)
	{
		vector_to_wall(data);
		data->pov.next_wall = *vector_y;
	}
	else if (data->pov.dir_angle == 360 || data->pov.dir_angle == 0)
	{
		vector_to_wall(data);
		data->pov.next_wall = *vector_x;
	}
	else if (data->pov.dir_angle == 180)
	{
		vector_to_wall(data);
		data->pov.next_wall = *vector_x;
	}
}
