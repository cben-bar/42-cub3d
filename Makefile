# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 15:41:52 by cben-bar          #+#    #+#              #
#    Updated: 2022/12/07 14:53:28 by mgolinva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror  #-fsanitize=address -g3

LIB_FLAG	=	-L mlx -l mlx

MLX_FLAGS	=	-framework OpenGL -framework Appkit

HEADER		=	-I includes -I mlx -I

INCL		=	./includes/cube.h ./includes/defines.h ./includes/structs.h ./mlx/mlx.h

SRCS =	srcs/main.c							\
		srcs/parsing/parsing.c				\
		srcs/parsing/ft_checks.c			\
		srcs/parsing/init_pars.c			\
		srcs/parsing/ft_tester.c			\
		srcs/parsing/check_flat_map.c		\
		srcs/parsing/find_map.c				\
		srcs/parsing/find_map_2.c			\
		srcs/parsing/find_map_3.c			\
		srcs/parsing/find_texture.c			\
		srcs/parsing/find_texture_2.c		\
		srcs/parsing/find_rgb.c				\
		srcs/parsing/find_rgb_2.c			\
		srcs/parsing/fill_map.c				\
		srcs/parsing/check_map.c			\
		srcs/parsing/check_map_2.c			\
		srcs/parsing/cross_check.c			\
		srcs/gnl/get_next_line_utils.c		\
		srcs/utils/ft_split.c				\
		srcs/utils/ft_manipulation_string.c	\
		srcs/utils/cleaner.c				\
		srcs/graphics/set_graphic.c			\
		srcs/graphics/map_drawer.c			\
		srcs/graphics/pixel.c				\
		srcs/graphics/square.c				\
		srcs/graphics/dda.c					\
		srcs/graphics/pythagore.c			\
		srcs/graphics/wall_hits.c			\
		srcs/graphics/vectors.c				\
		srcs/graphics/vector_to_next_wall.c	\
		srcs/graphics/cardinal_value.c		\
		srcs/graphics/fov.c					\
		srcs/graphics/fov_to_screen.c		\
		srcs/graphics/put_texture_to_wall.c	\
		srcs/gameplay/interractions.c		\
		srcs/gameplay/moves.c				\
		srcs/gameplay/ft_f_b_collision.c	\
		srcs/gameplay/ft_r_l_collision.c	\
		srcs/gameplay/rotates.c				\
		srcs/gameplay/angle.c				\
		
OBJS = $(SRCS:.c=.o)

LIB_MLX = ./mlx/libmlx.a 

all	: $(NAME)

%.o: %.c Makefile  $(INCL) ./mlx/libmlx.a 
	$(CC) -c $< -o $@ $(FLAGS)

$(NAME)	:	$(LIB_MLX) $(OBJS) $(INCL) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB_FLAG) $(MLX_FLAGS) 

$(LIB_MLX) : FORCE
	make -C ./mlx/

FORCE	:

clean	:
	make clean -C mlx
	rm -rf $(OBJS)

git		:	fclean
	git add *
	git add -u
	git commit

fclean	:	clean
	make clean -C mlx
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re git FORCE