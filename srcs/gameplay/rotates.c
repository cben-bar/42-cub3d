/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:47:49 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/05 18:34:35 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

t_bool	out_of_bounds(t_data *data, t_fcoo fcoo)
{
	if (fcoo.fx < 0 || fcoo.fx > data->pars->len_map)
		return (true);
	if (fcoo.fy < 0 || fcoo.fy > data->pars->height_map - 1)
		return (true);
	return (false);
}

void	rotate_left(t_data *data, int keycode)
{
	shift_angle(data, keycode);
	ft_actualyzer(data);
}

void	rotate_right(t_data *data, int keycode)
{
	shift_angle(data, keycode);
	ft_actualyzer(data);
}
