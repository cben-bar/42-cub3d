/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rgb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:14:48 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:34:12 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_valid_rgb(int code)
{
	if (code < 0 || code > 255)
		return (0);
	return (1);
}

void	witness_locker(t_data *data)
{
	if (data->pars->flag == 'F')
	{
		if (is_valid_rgb(data->pars->floor[0])
			&& is_valid_rgb(data->pars->floor[1])
			&& is_valid_rgb(data->pars->floor[2]))
			data->pars->witness_f = 1;
	}
	if (data->pars->flag == 'C')
	{
		if (is_valid_rgb(data->pars->ceilling[0])
			&& is_valid_rgb(data->pars->ceilling[1])
			&& is_valid_rgb(data->pars->ceilling[2]))
			data->pars->witness_c = 1;
	}
}

void	dispatch_value(char *s, int round, t_data *data)
{
	if (round == 0)
	{
		if (data->pars->flag == 'F')
			data->pars->floor[0] = ft_atoi(s, data);
		else
			data->pars->ceilling[0] = ft_atoi(s, data);
	}
	if (round == 1)
	{
		if (data->pars->flag == 'F')
			data->pars->floor[1] = ft_atoi(s, data);
		else
			data->pars->ceilling[1] = ft_atoi(s, data);
	}
	if (round == 2)
	{
		if (data->pars->flag == 'F')
			data->pars->floor[2] = ft_atoi(s, data);
		else
			data->pars->ceilling[2] = ft_atoi(s, data);
		witness_locker(data);
	}
}
