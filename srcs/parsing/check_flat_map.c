/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:27:37 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/06 21:11:13 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_filled_line(char *flatmap, int beg_map, t_data *data)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (flatmap[i] && i < beg_map)
	{
		while (flatmap[i] == '\n' || flatmap[i] == ' '
			|| (flatmap[i] >= 9 && flatmap[i] <= 13))
			i++;
		if (flatmap[i] && i < beg_map)
			ct++;
		while (flatmap[i] && flatmap[i] != '\n' && i < beg_map)
			i++;
	}
	if (ct != 6)
		free_and_quit("Invalid line", data);
}

void	check_flat_map(t_data *data, char *flatmap)
{
	int	beg_map;

	beg_map = get_map_begginning(flatmap);
	check_filled_line(flatmap, beg_map, data);
}
