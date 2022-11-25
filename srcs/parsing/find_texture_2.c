/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:08:57 by cben-bar          #+#    #+#             */
/*   Updated: 2022/11/16 16:14:07 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_valid_extension(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if ((path[i - 1] != 'm') || (path[i - 2] != 'p')
		|| (path[i - 3] != 'x') || (path[i - 4] != '.'))
		return (0);
	return (1);
}
