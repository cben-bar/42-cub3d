/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:35:01 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/07 11:19:08 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	init(t_data *data)
{
	minimap_size_init(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		free_and_quit("Mlx pointer assignation failed", data);
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H,
			"NTM_Sur_la_Cannebiere");
	data->fov.ptr = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->fov.addr = mlx_get_data_addr(data->fov.ptr, &data->fov.bits,
			&data->fov.line_size, &data->fov.endian);
	set_colors(data);
	xpm_to_images(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		free_and_quit("Bad argument", &data);
	parsing(&data, av[1]);
	init(&data);
	ft_actualyzer(&data);
	mlx_hook(data.win, 17, 0, close_mouse, &data);
	mlx_hook(data.win, 2, 0, keypress, &data);
	mlx_hook(data.win, 3, 0, keyrelease, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	cleaner(data.pars);
}
