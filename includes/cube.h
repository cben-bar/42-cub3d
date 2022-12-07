/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:35:22 by mgolinva          #+#    #+#             */
/*   Updated: 2022/12/07 14:53:09 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>
# include "defines.h"
# include "structs.h"

/***** WALL_HITS.c *****/

t_bool			is_it_a_vertical_wall_daddy(
					t_data *data, t_vector vector_x);
t_bool			is_it_a_horizontal_wall_daddy(t_data *data, t_vector vector_x);
void			get_vector_step(t_data *data, t_vector *vector, int marker);
void			vector_to_wall(t_data *data);

/***** VECTOR_TO_WALL.c *****/

void			vector_to_wall(t_data *data);

/***** KEY_ACTIONS.c *****/

int				keypress(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
int				close_mouse(t_data *data);
int				ft_exit(t_data *data);

/***** MOVES.c *****/

void			set_fov(t_data *data);
void			draw_line(t_data *data, double angle, int side);
void			move_forward(t_data *data);
t_bool			this_is_f_b_collision(t_data *data, int direction);
t_bool			this_is_r_l_collision(t_data *data, float x1, float y1);
void			move_backward(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);
void			ft_actualyzer(t_data *data);
t_bool			out_of_bounds(t_data *data, t_fcoo fcoo);

/***** FOV.c *****/

void			fov(t_data *data);
double			calculate_angle_shifter(int angle_shifts);

/***** ROTATE.c *****/

void			rotate_left(t_data *data, int keycode);
void			rotate_right(t_data *data, int keycode);

/***** ANGLES.c *****/

double			get_angle(double angle_to_x);
void			shift_angle(t_data *data, int keycode);
void			change_quadrant(t_data *data);

/***** PYTHAGORE.c *****/

double			hypothenus(t_vector *vector);

/***** PIXEL.c *****/

void			pixel_put(t_img *img, int x, int y, int color);
int				get_text_pixel(t_img wall, int x, int y);

/***** VECTORS.c *****/

t_bool			get_next_horizontal_line(
					t_data *data, t_vector *vector, t_fcoo starting_coo);
t_bool			get_next_vertical_line(
					t_data *data, t_vector *vector, t_fcoo starting_coo);
void			cardinal_value_handler(t_data *data,
					t_vector *vector_x, t_vector *vector_y);

/***** DDA.c *****/

void			dda(t_data *data, t_img *img, t_vector vector, int color);

/***** FOV_TO_SCREEN.c *****/

void			pttw(t_data *data, t_img *fov, int x, int y);

/***** FOV_TO_SCREEN.c *****/

void			put_fov_to_screen(
					t_data *data, t_vector *next_wall,
					double angle, int angle_shift);

/***** MAP_DRAWER.c *****/

void			draw_map(t_img *map_img, char **map_tab);
void			set_colors(t_data *data);
void			xpm_to_images(t_data *data);
void			xpm_to_images_2(t_data *data);
void			minimap_size_init(t_data *data);

/***** SQUARE.c *****/

void			ft_square_maker(t_square square, t_img *img, int color);
void			ft_square_filler(t_square square, t_img *img, int color);
void			ft_point_player(t_square square, t_img *img, int color);

/***** PARSING.c *****/

void			parsing(t_data *data, const char *filename);
void			check_extension(const char *filename, t_data *data);
int				is_valid_extension(char *path);
void			check_path(const char *filename, t_data *data);
void			init_pars(t_data *data);
char			*joiner(int fd);
void			check_flat_map(t_data *data, char *flat);
int				find_beg_map(char *flat, int i, int j, int check);
void			find_map(char *flat, t_data *data);
void			check_empty_line(char *flat, t_data *data);
int				is_in_charset(char c);
int				find_len_map(char *flat, int i);
int				new_line_counter(char *flat);
void			fill_struct(t_data *data, char *flat_map, int i, int j);
void			find_texture(char **tab, t_data *data);
void			fill_map_to_run(t_data *data);
void			check_map(t_data *data);
void			check_char_map(t_data *data);
int				is_wrong_charset(char c);
void			check_just_one_player(char **map, t_data *data);
void			get_player_pos(char **map, t_data *data);
void			cross_check(char **map, t_data *data);
void			find_rgb(char **tab, t_data *data);
int				is_valid_line(char *line, char to_find, int v);
void			dispatch_value(char *s, int round, t_data *data);
void			check_pars(t_data *data);
int				is_player(char c);
int				get_map_begginning(char *flat);

/***** UTILS.c *****/

void			free_and_quit(char *msg, t_data *data);
void			close_map(int fd, char *msg, t_data *data);
void			freeer_tab(char **tab);
size_t			ft_strlen(const char *s);
int				ft_strlen2d(char **array);
char			**ft_split(char const *s, char c);
void			cleaner(t_pars *pars);
char			*ft_strcpy(char *dst, char *src);
int				ft_isdigit(int c);
char			*ft_cjoin(const char *s1, char s2);
char			*ft_sjoin(const char *s1, const char *s2);
int				ft_atoi(const char *str, t_data *data);

/***** TEST.c *****/

void			ft_printer_double_tab(char **tab);
void			print_int_tab(int *map_tab);

/******** GNL ********/

char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strchr(const char *str, int x);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, int n);

#endif