/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:17:50 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/16 17:26:37 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_empty_line(char *flat, t_data *data)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (flat[i])
	{
		if (flat[i] == '\n')
			nl++;
		i++;
	}
	data->pars->nl = nl;
}

int	new_line_counter(char *flat)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (flat[i])
	{
		if (flat[i] == '\n')
			nl++;
		if (flat[i] != '\n')
			nl = 0;
		if (nl == 2)
			return (0);
		i++;
	}
	return (1);
}
