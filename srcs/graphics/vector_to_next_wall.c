/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_next_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:30:28 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/02 10:29:16 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	vertical(t_data *data)
{
	if ((is_it_a_vertical_wall_daddy(data, data->pov.vector_x) == true)
		|| (data->pov.dir_angle == 90 || data->pov.dir_angle == 270))
		return ;
	while (out_of_bounds(data, data->pov.vector_x.direction) == false)
	{
		if ((data->pov.dir_angle == 0 || data->pov.dir_angle == 360
				|| data->pov.dir_angle == 180))
				data->pov.vector_x.direction.fy = data->pov.fcoo.fy;
		else if (data->pov.quadrant == FIRST_Q
			|| data->pov.quadrant == SECOND_Q)
			data->pov.vector_x.direction.fy -= data->pov.vector_x.step_y;
		else
			data->pov.vector_x.direction.fy += data->pov.vector_x.step_y;
		if (data->pov.quadrant == SECOND_Q || data->pov.quadrant == THIRD_Q)
			data->pov.vector_x.direction.fx += 1;
		else
			data->pov.vector_x.direction.fx -= 1;
		if (is_it_a_vertical_wall_daddy(data, data->pov.vector_x) == true)
			break ;
	}
}

static void	horizontal(t_data *data)
{
	if ((is_it_a_horizontal_wall_daddy(data, data->pov.vector_y) == true)
		|| (data->pov.dir_angle == 0 || data->pov.dir_angle == 180))
		return ;
	while (out_of_bounds(data, data->pov.vector_y.direction) == false)
	{
		if ((data->pov.dir_angle == 90
				|| data->pov.dir_angle == 270))
				data->pov.vector_y.direction.fx = data->pov.fcoo.fx;
		else if (data->pov.quadrant == SECOND_Q
			|| data->pov.quadrant == THIRD_Q)
			data->pov.vector_y.direction.fx += data->pov.vector_y.step_x;
		else
			data->pov.vector_y.direction.fx -= data->pov.vector_y.step_x;
		if (data->pov.quadrant == FIRST_Q || data->pov.quadrant == SECOND_Q)
			data->pov.vector_y.direction.fy -= 1;
		else
			data->pov.vector_y.direction.fy += 1;
		if (is_it_a_horizontal_wall_daddy(data, data->pov.vector_y) == true)
			break ;
	}
}

void	vector_to_wall(t_data *data)
{
	get_vector_step(data, &data->pov.vector_x, X);
	get_vector_step(data, &data->pov.vector_y, Y);
	vertical(data);
	horizontal(data);
}
