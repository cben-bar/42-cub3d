/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:36:58 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/18 16:32:57 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_square_filler(t_square square, t_img *img, int color)
{
	int	x;
	int	y;

	x = square.top_x + 1;
	while (x <= square.bot_x - 1)
	{
		y = square.top_y + 1;
		while (y <= square.bot_y - 1)
		{
			pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_square_maker(t_data *data, t_square square, t_img *img, int color)
{
	int i;

	(void) data;
	i = square.top_x - 1;
	while (i++ < square.bot_x)
		pixel_put(img, i, square.top_y, color);
	i = square.top_x - 1;
	while (i++ < square.bot_x)
		pixel_put(img, i, square.bot_y, color);
	i = square.top_y - 1;
	while (i++ < square.bot_y)
		pixel_put(img, square.top_x, i, color);
	i = square.top_y - 1;
	while (i++ < square.bot_y)
		pixel_put(img, square.bot_x, i, color);
}