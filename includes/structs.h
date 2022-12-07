/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:17:39 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/06 21:04:31 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_coo
{
	int	x;
	int	y;
}	t_coo;

typedef struct s_fcoo
{
	float	fx;
	float	fy;
}	t_fcoo;

typedef struct s_vector
{
	t_fcoo	start;
	t_fcoo	direction;
	double	dx;
	double	dy;
	double	step_y;
	double	step_x;
	double	length;
}	t_vector;

typedef struct s_square
{
	int	top_x;
	int	top_y;
	int	bot_x;
	int	bot_y;
}		t_square;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits;
	int		line_size;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_pov
{
	t_fcoo		fcoo;
	double		dir_angle;
	int			quadrant;
	int			wall_type;
	double		wall_height;
	t_vector	vector_x;
	t_vector	vector_y;
	t_vector	next_wall;
}	t_pov;

typedef struct s_pars
{
	char	*no;
	int		witness_no;
	char	*so;
	int		witness_so;
	char	*we;
	int		witness_we;
	char	*ea;
	int		witness_ea;
	int		floor[3];
	int		witness_f;
	int		ceilling[3];
	int		witness_c;
	char	flag;
	int		nl;
	int		height_map;
	int		len_map;
	char	**map;
	int		witness_player;
}	t_pars;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		ceilling_color;
	int		floor_color;
	t_pov	pov;
	t_img	wall[4];
	t_img	map_img;
	t_img	fov;
	t_pars	*pars;
	t_bool	keyboard[200];
}			t_data;

#endif