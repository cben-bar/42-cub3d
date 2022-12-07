/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:36:58 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 20:44:43 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	sqr_heights(t_square square, t_img *img, int color)
{
	int	i;

	i = square.top_y - 1;
	while (i++ < square.bot_y)
	{
		if (i >= WIN_H || square.top_x >= WIN_W)
		{
			return (-1);
		}
		pixel_put(img, square.top_x, i, color);
	}
	i = square.top_y - 1;
	while (i++ < square.bot_y)
	{
		if (i >= WIN_H || square.bot_x >= WIN_W)
			return (-1);
		pixel_put(img, square.bot_x, i, color);
	}
	return (0);
}

static int	sqr_widths(t_square square, t_img *img, int color)
{
	int	i;

	i = square.top_x - 1;
	while (i++ < square.bot_x)
	{
		if (i >= WIN_W || square.top_y + 512 > WIN_H)
			return (-1);
		pixel_put(img, i, square.top_y, color);
	}
	i = square.top_x - 1;
	while (i++ < square.bot_x)
	{
		if (i >= WIN_W || square.top_y + 512 > WIN_H)
			return (-1);
		pixel_put(img, i, square.bot_y, color);
	}
	return (0);
}

void	ft_square_maker(t_square square, t_img *img, int color)
{
	if (sqr_heights(square, img, color) == -1)
		return ;
	if (sqr_widths(square, img, color) == -1)
		return ;
}

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
			if (x >= WIN_W || y >= WIN_H)
				return ;
			pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}
