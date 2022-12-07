/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:12:13 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 14:35:17 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	find_len(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] && line[i] != ',')
	{
		if (ft_isdigit(line[i]))
			len++;
		i++;
	}
	return (len);
}

char	*cpy_value(char *line, t_data *data)
{
	int		len;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	len = find_len(line);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		free_and_quit("Error : Allocation memory", data);
	while (line[i] && line[i] != ',')
	{
		if (ft_isdigit(line[i]))
		{
			s[j] = line[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
	return (s);
}

void	get_value(char *line, t_data *data)
{
	int		i;
	int		round;
	char	*s;

	i = 0;
	round = 0;
	while (line[i] && round < 3)
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		s = cpy_value(&line[i], data);
		dispatch_value(s, round, data);
		round++;
		while (line[i])
		{
			if (line[i] == ',')
				break ;
			i++;
		}
		free(s);
	}
}

int	is_valid_line(char *line, char to_find, int v)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != 9 && !ft_isdigit(line[i])
			&& line[i] != ',' && line[i] != to_find)
			return (0);
		if (line[i] == to_find)
		{
			check++;
			if (check > 1)
				return (0);
		}
		if (line[i] == ',')
			v++;
		i++;
	}
	if (v != 2)
		return (0);
	if (check == 1)
		return (1);
	return (0);
}

void	find_rgb(char **tab, t_data *data)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (is_valid_line(tab[i], 'F', 0) && !data->pars->witness_f)
		{
			data->pars->flag = 'F';
			get_value(tab[i], data);
		}
		if (is_valid_line(tab[i], 'C', 0) && !data->pars->witness_c)
		{
			data->pars->flag = 'C';
			get_value(tab[i], data);
		}
		i++;
	}
}
