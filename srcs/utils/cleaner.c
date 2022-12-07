/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:16:17 by cben-bar          #+#    #+#             */
/*   Updated: 2022/12/01 18:24:10 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	cleaner(t_pars *pars)
{
	free(pars->no);
	free(pars->so);
	free(pars->we);
	free(pars->ea);
	if (pars->map)
		freeer_tab(pars->map);
	free (pars);
}

void	freeer_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_and_quit(char *msg, t_data *data)
{
	if (data->pars)
		cleaner(data->pars);
	printf("Error 🤯\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	close_map(int fd, char *msg, t_data *data)
{
	close(fd);
	free_and_quit(msg, data);
}
