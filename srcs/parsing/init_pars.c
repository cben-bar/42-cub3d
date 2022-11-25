/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:46:11 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/18 17:23:28 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	init_pars_2(t_data *data)
{
	data->pars->witness_c = 0;
	data->pars->flag = '0';
	data->pars->height_map = 0;
	data->pars->len_map = 0;
	data->pars->map = NULL;
	data->pars->witness_player = 0;
}

void	init_pars(t_data *data)
{
	data->pars = malloc(sizeof(t_pars));
	if (!data->pars)
		free_and_quit("Allocation memory", data);
	data->pars->no = NULL;
	data->pars->witness_no = 0;
	data->pars->so = NULL;
	data->pars->witness_so = 0;
	data->pars->we = NULL;
	data->pars->witness_we = 0;
	data->pars->ea = NULL;
	data->pars->witness_ea = 0;
	data->pars->witness_f = 0;
	init_pars_2(data);
}
