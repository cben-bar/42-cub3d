/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:27 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/02 10:26:21 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_size + x * (img->bits / 8)));
	*(unsigned int *)pixel = color;
}

int	get_text_pixel(t_img wall, int x, int y)
{
	int	color;

	if (x < 0 || x >= wall.width)
		return (0);
	if (y < 0 || y >= wall.height)
		return (0);
	color = (*(int *)(wall.addr
				+ (y * wall.line_size) + (x * wall.bits / 8)));
	return (color);
}
