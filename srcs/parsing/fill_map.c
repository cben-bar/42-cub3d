/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:55:19 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 10:44:55 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_in_micro_charset(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	fill_it(char *origin, t_data *data, int i)
{
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * data->pars->len_map + 1);
	if (!tmp)
		free_and_quit("Error: memory Allocation", data);
	j = 0;
	while (origin[j])
	{
		if (origin[j] == ' ')
			tmp[j] = 'X';
		else if (is_in_micro_charset(origin[j]))
			tmp[j] = origin[j];
		j++;
	}
	while (j < data->pars->len_map)
	{
		tmp[j] = 'X';
		j++;
	}
	tmp[j] = '\0';
	free(data->pars->map[i]);
	data->pars->map[i] = ft_strdup(tmp);
	free(tmp);
}

void	fill_map_to_run(t_data *data)
{
	int	i;

	i = 0;
	while (data->pars->map[i])
	{
		fill_it(data->pars->map[i], data, i);
		i++;
	}
}
