/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:47:32 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/23 15:02:34 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	set_remarkable_point_first_q(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{
	vector_y->direction.fx = vector_y->start.fx;
	vector_y->direction.fy = vector_y->start.fy;
	vector_x->direction.fx = (int)data->pov.fcoo.fx;
	vector_x->direction.fy = vector_x->start.fy;
}

void	set_remarkable_point_second_q(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{	
	vector_x->direction.fx = vector_x->start.fx;
	vector_x->direction.fy = vector_x->start.fy;
	vector_y->direction.fx = vector_y->start.fx;
	vector_y->direction.fy = (int)data->pov.fcoo.fy;
}

void	set_remarkable_point_third_q(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{
	vector_y->direction.fx = vector_y->start.fx;
	vector_y->direction.fy = vector_y->start.fy;
	vector_x->direction.fx = (int)data->pov.fcoo.fx + 1;
	vector_x->direction.fy = vector_x->start.fy;
}

void	set_remarkable_point_forth_q(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{
	vector_x->direction.fx = vector_x->start.fx;
	vector_x->direction.fy = vector_x->start.fy;
	vector_y->direction.fx = vector_y->start.fx;
	vector_y->direction.fy = (int)data->pov.fcoo.fy + 1;
}

void	cardinal_value_handler(t_data *data,
	t_vector *vector_x, t_vector *vector_y)
{
	vector_x->start.fx = data->pov.fcoo.fx;
	vector_x->start.fy = data->pov.fcoo.fy;
	vector_y->start.fx = data->pov.fcoo.fx;
	vector_y->start.fy = data->pov.fcoo.fy;
	if (data->pov.direction_angle == 90)
		set_remarkable_point_second_q(data, vector_x, vector_y);
	else if (data->pov.direction_angle == 270)
		set_remarkable_point_forth_q(data, vector_x, vector_y);
	else if (data->pov.direction_angle == 0)
		set_remarkable_point_first_q(data, vector_x, vector_y);
	else if (data->pov.direction_angle == 180)
		set_remarkable_point_third_q(data, vector_x, vector_y);
}
