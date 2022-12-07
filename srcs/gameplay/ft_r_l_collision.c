/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_l_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:18 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/06 21:16:15 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_bool	this_is_r_l_collision(t_data *data, float x1, float y1)
{
	if (data->pars->map[(int)ceil(data->pov.fcoo.fy + y1) - 1]
		[(int)ceil(data->pov.fcoo.fx + x1) - 1])
	{
		if (data->pars->map[(int)ceil((double)data->pov.fcoo.fy
					+ (double)y1) - 1]
			[(int)ceil((double)data->pov.fcoo.fx + (double)x1) - 1] == '1'
			|| data->pars->map[(int)ceil((double)data->pov.fcoo.fy
					+ (double)y1) - 1]
			[(int)ceil((double)data->pov.fcoo.fx + (double)x1) - 1] == 'X')
			return (true);
	}
	return (false);
}
