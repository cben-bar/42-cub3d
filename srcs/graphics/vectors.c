/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:57:09 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/02 10:29:54 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	je_suis_un_peintre(t_data *data, t_vector *vector, t_vector tmp_vec)
{
	if (data->pov.dir_angle < 90 || data->pov.dir_angle > 270)
	{
		tmp_vec.start.fy = vector->direction.fy;
		tmp_vec.start.fx = vector->direction.fx;
		tmp_vec.direction.fx = tmp_vec.start.fx - 1;
		tmp_vec.dx = 1;
		tmp_vec.dy = tmp_vec.dx * tan(get_angle(data->pov.dir_angle));
		vector->step_x = tmp_vec.dx;
		vector->step_y = tmp_vec.dy;
	}
	else if (data->pov.dir_angle > 90 && data->pov.dir_angle < 270)
	{
		tmp_vec.start.fy = vector->direction.fy;
		tmp_vec.start.fx = vector->direction.fx;
		tmp_vec.direction.fx = tmp_vec.start.fx + 1;
		tmp_vec.dx = 1;
		tmp_vec.dy = tmp_vec.dx * tan(get_angle(data->pov.dir_angle));
		vector->step_x = tmp_vec.dx;
		vector->step_y = tmp_vec.dy;
	}
}

static void	en_batiment(t_data *data, t_vector *vector, t_vector tmp_vec)
{
	if (data->pov.dir_angle > 180 && data->pov.dir_angle < 360)
	{
		tmp_vec.start.fy = vector->direction.fy;
		tmp_vec.start.fx = vector->direction.fx;
		tmp_vec.direction.fy = tmp_vec.start.fy + 1;
		tmp_vec.dy = 1;
		tmp_vec.dx = tmp_vec.dy / tan(get_angle(data->pov.dir_angle));
		vector->step_x = tmp_vec.dx;
		vector->step_y = tmp_vec.dy;
	}
	if (data->pov.dir_angle > 0 && data->pov.dir_angle < 180)
	{
		tmp_vec.start.fy = vector->direction.fy;
		tmp_vec.start.fx = vector->direction.fx;
		tmp_vec.direction.fy = tmp_vec.start.fy - 1;
		tmp_vec.dy = 1;
		tmp_vec.dx = tmp_vec.dy / tan(get_angle(data->pov.dir_angle));
		vector->step_x = tmp_vec.dx;
		vector->step_y = tmp_vec.dy;
	}
}

void	get_vector_step(t_data *data, t_vector *vector, int marker)
{
	t_vector	tmp_vec;

	tmp_vec = *vector;
	if (data->pov.dir_angle == 90 || data->pov.dir_angle == 270)
	{
		vector->step_x = 0;
		vector->step_y = 1;
		return ;
	}
	else if (data->pov.dir_angle == 0 || data->pov.dir_angle == 180)
	{
		vector->step_x = 1;
		vector->step_y = 0;
		return ;
	}
	if (marker == X)
		je_suis_un_peintre(data, vector, tmp_vec);
	else if (marker == Y)
		en_batiment(data, vector, tmp_vec);
}

t_bool	get_next_vertical_line(
	t_data *data, t_vector *vector, t_fcoo starting_coo)
{
	vector->start.fx = starting_coo.fx;
	vector->start.fy = starting_coo.fy;
	if (data->pov.dir_angle < 90 || data->pov.dir_angle > 270)
	{
		vector->direction.fx = floor(vector->start.fx);
		vector->dx = vector->start.fx - vector->direction.fx;
		vector->dy = vector->dx * tan(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.dir_angle > 90 && data->pov.dir_angle < 270)
	{
		vector->direction.fx = ceil(vector->start.fx);
		vector->dx = vector->direction.fx - vector->start.fx;
		vector->dy = vector->dx * tan(get_angle(data->pov.dir_angle));
	}
	else
		return (false);
	if (data->pov.dir_angle > 180 && data->pov.dir_angle < 360)
		vector->direction.fy = vector->start.fy + vector->dy;
	else if (data->pov.dir_angle > 0 && data->pov.dir_angle < 180)
		vector->direction.fy = vector->start.fy - vector->dy;
	return (true);
}

t_bool	get_next_horizontal_line(
	t_data *data, t_vector *vector, t_fcoo starting_coo)
{
	vector->start.fx = starting_coo.fx;
	vector->start.fy = starting_coo.fy;
	if (data->pov.dir_angle > 180 && data->pov.dir_angle < 360)
	{
		vector->direction.fy = ceil(vector->start.fy);
		vector->dy = vector->direction.fy - vector->start.fy;
		vector->dx = vector->dy / tan(get_angle(data->pov.dir_angle));
	}
	else if (data->pov.dir_angle > 0 && data->pov.dir_angle < 180)
	{
		vector->direction.fy = floor(vector->start.fy);
		vector->dy = vector->start.fy - vector->direction.fy;
		vector->dx = vector->dy / tan(get_angle(data->pov.dir_angle));
	}
	else
		return (false);
	if (data->pov.dir_angle < 90 || data->pov.dir_angle > 270)
		vector->direction.fx = vector->start.fx - vector->dx;
	else if (data->pov.dir_angle > 90 && data->pov.dir_angle < 270)
		vector->direction.fx = vector->start.fx + vector->dx;
	return (true);
}
