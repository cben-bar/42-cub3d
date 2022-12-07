/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pythagore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:43:11 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/05 16:28:23 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

double	hypothenus(t_vector *vector)
{
	double	hp;

	vector->dx = vector->direction.fx - vector->start.fx;
	vector->dy = vector->direction.fy - vector->start.fy;
	hp = vector->dx * vector->dx + vector->dy * vector->dy;
	hp = sqrt(hp);
	return (hp);
}
