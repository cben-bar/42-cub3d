/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:27 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/18 15:53:31 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	pixel = img->addr + ((y * img->line_size + x * (img->bits / 8)));
	*(unsigned int*)pixel = color;
}
