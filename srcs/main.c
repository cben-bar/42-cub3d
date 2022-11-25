/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:35:01 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/25 13:38:14 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	ft_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	cleaner(data->pars);
	printf("Bye!\n");
	exit (EXIT_SUCCESS);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode < 200)
		data->keyboard[keycode] = true;
	if (data->keyboard[ESC] == true)
		ft_exit(data);
	if (data->keyboard[W] == true)
		move_forward(data);
	if (data->keyboard[S] == true)
		move_backward(data);
	if (data->keyboard[A] == true)
		move_left(data);
	if (data->keyboard[D] == true)
		move_right(data);
	if (data->keyboard[E] == true)
		rotate_right(data, keycode);
	if (data->keyboard[Q] == true)
		rotate_left(data, keycode);
	return (0);
}

int keyrelease(int keycode, t_data *data)
{
	if (keycode < 200)
		data->keyboard[keycode] = false;
	return (0);
}

int close_mouse(t_data *data)
{
	ft_exit(data);
	return (0);
}

int main(int ac, char **av)
{
	t_data data;

	parsing(&data, ac, av[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "Ubrisoft");
	data.map_img.ptr = mlx_new_image(data.mlx, WIN_W, WIN_H);
	data.map_img.addr = mlx_get_data_addr(data.map_img.ptr, &data.map_img.bits,
	&data.map_img.line_size, &data.map_img.endian);
	draw_map(&data, &data.map_img, data.pars->map);
	ft_actualyzer(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.map_img.ptr, 0, 0);
	mlx_hook(data.win, 17, 0, close_mouse, &data);
	mlx_hook(data.win, 2, 0, keypress, &data);
	mlx_hook(data.win, 3, 0, keyrelease, &data);
	mlx_loop(data.mlx);
	// mlx_destroy_window(data.mlx, data.win);
	// cleaner(data.pars);
}

// faire tt ca et push avant le 10 decembre