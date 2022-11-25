/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:52:07 by cben-bar          #+#    #+#             */
/*   Updated: 2022/10/27 17:20:43 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	check_extension(const char *filename, t_data *data)
{
	size_t	i;

	i = ft_strlen(filename);
	if ((filename[i - 1] != 'b') || (filename[i - 2] != 'u')
		|| (filename[i - 3] != 'c') || (filename[i - 4] != '.'))
		free_and_quit("Bad extension", data);
}

void	check_path(const char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free_and_quit("File does not exist", data);
	}
	else
		close(fd);
}
