/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:42:09 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/16 17:09:20 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	set_pars_1(int flag, char *path, t_data *data)
{
	if (!is_valid_extension(path))
		return ;
	if (flag == 1 && data->pars->witness_no == 0)
	{
		data->pars->no = ft_strdup(path);
		data->pars->witness_no = 1;
	}
	else if (flag == 2 && data->pars->witness_so == 0)
	{
		data->pars->so = ft_strdup(path);
				data->pars->witness_so = 1;
	}
	else if (flag == 3 && data->pars->witness_we == 0)
	{
		data->pars->we = ft_strdup(path);
		data->pars->witness_we = 1;
	}
	else if (flag == 4 && data->pars->witness_ea == 0)
	{
		data->pars->ea = ft_strdup(path);
		data->pars->witness_ea = 1;
	}
}

void	check_path_text_1(char *path, int flag, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		close(fd);
	else
	{
		close(fd);
		set_pars_1(flag, path, data);
	}	
}

int	serach_2(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

int	search_1(int check, char *line, char first, char twice)
{
	int		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == first)
		{
			check++;
			i++;
		}
		while (line[i] == ' ')
			i++;
		if (line[i] == twice)
		{
			check++;
			i++;
		}
		if (check == 2)
			break ;
		else
			check = 0;
		i++;
	}
	if (check == 2)
		return (serach_2(line, i));
	else
		return (0);
}

void	find_texture(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = search_1(0, tab[i], 'N', 'O');
		if (j)
			check_path_text_1(&tab[i][j], 1, data);
		j = search_1(0, tab[i], 'S', 'O');
		if (j)
			check_path_text_1(&tab[i][j], 2, data);
		j = search_1(0, tab[i], 'W', 'E');
		if (j)
			check_path_text_1(&tab[i][j], 3, data);
		j = search_1(0, tab[i], 'E', 'A');
		if (j)
			check_path_text_1(&tab[i][j], 4, data);
		i++;
	}
}
