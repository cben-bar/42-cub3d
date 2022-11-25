/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:02 by mgolinva          #+#    #+#             */
/*   Updated: 2022/11/23 21:11:34 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef DEFINE_H
# define DEFINE_H

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define GREY 0x00BFBFBF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define PURPLE 0x00FF00FF
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define PINK 0x00DD88BB

# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define SPACE 49
# define TAB 48
# define ESC 53

# define STEP 0.2
# define ROTATION 10

# define SOUTH	0
# define NORTH	1
# define EAST	2
# define WEST	3

# define DEGREE_L -0.1745329
# define DEGREE_R 0.1745329
# define PI_2 1.57
# define PI 3.14
# define LEFT 0
# define RIGHT 1

# define X 0
# define Y 1

# define BUFFER_SIZE 1

# define WIN_W 1664
# define WIN_H 1024
# define MAP_SQUARE 64

# define FOV 60
# define FIRST_Q 1 // 0 a 90 degres, 0 inclus
# define SECOND_Q 2 // 90 a 180 degres, 90 inclus
# define THIRD_Q 3 // 180 a 270 degres, 180 inclus
# define FORTH_Q 4 // 270 a 360 degres, 270 inclus

#endif