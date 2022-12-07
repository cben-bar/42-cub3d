/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:20:16 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/07 10:46:40 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_pars(t_data *data)
{
	if (data->pars->witness_no == 0)
		free_and_quit("Missing info: north texture.", data);
	if (data->pars->witness_so == 0)
		free_and_quit("Missing info: south texture.", data);
	if (data->pars->witness_we == 0)
		free_and_quit("Missing info: weast texture.", data);
	if (data->pars->witness_ea == 0)
		free_and_quit("Missing info: east texture.", data);
	if (data->pars->witness_f == 0)
		free_and_quit("Missing info: floor color.", data);
	if (data->pars->witness_c == 0)
		free_and_quit("Missing info: ceiling color.", data);
}

char	*ft_sjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	if (s1)
	{
		while (s1[++i])
			joined[i] = s1[i];
	}
	else
		i++;
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[len] = '\0';
	return (joined);
}

char	*joiner(int fd)
{
	int		i;
	char	s[11];
	char	*tmp;
	char	*conc;

	conc = NULL;
	i = read(fd, s, 10);
	while (i > 0)
	{
		s[i] = '\0';
		tmp = conc;
		conc = ft_sjoin(tmp, s);
		if (tmp)
			free(tmp);
		i = read(fd, s, 10);
	}
	return (conc);
}

void	parsing(t_data *data, const char *filename)
{
	int		fd;
	char	*flat;
	char	**tab;

	fd = open(filename, O_RDONLY);
	if (fd < 1 && fd > OPEN_MAX)
		return (close_map(fd, "File descriptor default", data));
	check_extension(filename, data);
	check_path(filename, data);
	init_pars(data);
	flat = joiner(fd);
	close(fd);
	if (!flat)
		return (close_map(fd, "Empty map", data));
	check_flat_map(data, flat);
	tab = ft_split(flat, '\n');
	find_map(flat, data);
	free(flat);
	find_texture(tab, data);
	find_rgb(tab, data);
	fill_map_to_run(data);
	check_map(data);
	check_pars(data);
	freeer_tab(tab);
}
