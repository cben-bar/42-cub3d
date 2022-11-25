/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:47:01 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/18 17:29:06 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	parsing_printer_2(t_data *data, int i)
{
	printf("\n =====================================\n\n");
	printf("flag =%c\n", data->pars->flag);
	printf("\n =====================================\n\n");
	printf("height_map =%d\n", data->pars->height_map);
	printf("\n =====================================\n\n");
	printf("len_map =%d\n", data->pars->len_map);
	printf("\n =====================================\n\n");
	if (data->pars->map)
	{
		while (data->pars->map[i])
		{
			printf("data->pars->map[%d] =\t%s\t\t", i, data->pars->map[i]);
			printf("len: %zu\n", ft_strlen(data->pars->map[i]));
			i++;
		}
	}	
	printf("\n =====================================\n\n");
	printf("data->pov.direction_angle =%d\n", data->pov.direction_angle);
	printf("N = 90, S = 270, E = 0, W = 180\n");
	printf("\n =====================================\n\n");
	printf("data->pov.fcoo.fy =%f\n", data->pov.fcoo.fy);
	printf("\n =====================================\n\n");
	printf("data->pov.fcoo.fx =%f\n", data->pov.fcoo.fx);
	printf("\n =====================================\n\n");
	printf("witness_player =%d\n", data->pars->witness_player);
	printf("\n =====================================\n\n");
}

void	parsing_printer(t_data *data, int i)
{
	printf("\n ===============Printer===============\n\n");
	printf("data->pars->no =%s\n", data->pars->no);
	printf("witness_no =%d\n", data->pars->witness_no);
	printf("\n =====================================\n\n");
	printf("data->pars->so =%s\n", data->pars->so);
	printf("witness_so =%d\n", data->pars->witness_so);
	printf("\n =====================================\n\n");
	printf("data->pars->we =%s\n", data->pars->we);
	printf("witness_we =%d\n", data->pars->witness_we);
	printf("\n =====================================\n\n");
	printf("data->pars->ea =%s\n", data->pars->ea);
	printf("witness_ea =%d\n", data->pars->witness_ea);
	printf("\n =====================================\n\n");
	printf("r_f =%d\n", data->pars->floor[0]);
	printf("g_f =%d\n", data->pars->floor[1]);
	printf("b_f =%d\n", data->pars->floor[2]);
	printf("witness_f =%d\n", data->pars->witness_f);
	printf("\n =====================================\n\n");
	printf("r_c =%d\n", data->pars->ceilling[0]);
	printf("g_c =%d\n", data->pars->ceilling[1]);
	printf("b_c =%d\n", data->pars->ceilling[2]);
	printf("witness_c =%d\n", data->pars->witness_c);
	parsing_printer_2(data, i);
}
