/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interractions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:12:11 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 20:28:32 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	ft_exit(t_data *data)
{
	if (data->mlx && data->win != NULL)
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
	if (data->keyboard[E] == true || data->keyboard[RIGHT_A] == true)
		rotate_right(data, keycode);
	if (data->keyboard[Q] == true || data->keyboard[LEFT_A] == true)
		rotate_left(data, keycode);
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode < 200)
		data->keyboard[keycode] = false;
	return (0);
}

int	close_mouse(t_data *data)
{
	ft_exit(data);
	return (0);
}
