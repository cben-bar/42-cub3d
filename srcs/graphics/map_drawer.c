/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:11:49 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/24 16:25:38 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->map_img.addr + (y * data->pars->len_map + x * (data->map_img.bits / 8));
	*(unsigned int*)dst = color;
}

void	set_square(t_square *cube, int y, int x)
{
	cube->top_x = x * MAP_SQUARE;
	cube->top_y = y * MAP_SQUARE;
	cube->bot_x = (x + 1) * MAP_SQUARE;
	cube->bot_y = (y + 1) * MAP_SQUARE;
}

void	draw_map(t_data *data, t_img *map_img, char **map_tab)
{
	int			x;
	int			y;
	t_square	cube;

	y = 0;
	while(map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			set_square(&cube, y, x);
			if (map_tab[y][x] == '1')
			{
				ft_square_maker(data, cube, map_img, WHITE);
				ft_square_filler(cube, map_img, GREY);
			}
			else if (map_tab[y][x] == '0')
				ft_square_maker(data, cube, map_img, GREY);
			else if (is_player(map_tab[y][x]))
				pixel_put(&data->map_img, (x * (MAP_SQUARE)), y * (MAP_SQUARE), MAGENTA);
			x++;
		}
		y++;
	}
}