/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:42:09 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 10:20:10 by cben-bar         ###   ########lyon.fr   */
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
	{
		close(fd);
		free_and_quit("Invalid line", data);
	}
	else
	{
		close(fd);
		set_pars_1(flag, path, data);
	}	
}

int	search_2(char *line, int i)
{
	if ((size_t) i > ft_strlen(line))
		return (0);
	while ((line[i])
		&& (line[i] == ' ' || line[i] == 9))
			i++;
	return (i);
}

int	search_1(int check, char *line, char first, char twice)
{
	int		i;

	i = 0;
	i = search_2(line, i);
	if (line[i] && line[i] == first && check == 0)
		check++;
	i++;
	i = search_2(line, i);
	if (line[i] && line[i] == twice && check == 1)
		check++;
	i++;
	if (check == 2)
		return (search_2(line, i));
	return (0);
}

void	find_texture(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab != NULL && tab[i])
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
