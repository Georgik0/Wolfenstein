# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skitsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 17:13:13 by skitsch           #+#    #+#              #
#    Updated: 2021/01/08 17:13:21 by skitsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = start_game.c find_block_unique.c find_collision.c \
find_block_horisontal.c find_block_vertical.c draw_3d.c get_length.c \
put_pixel_texture.c get_sprite.c draw_sprite.c get_calc.c get_next_line.c \
get_next_line_utils.c parser.c get_param.c get_screen_param.c \
get_texture.c get_texture_1.c make_malloc_vars.c get_floor_and_celling.c \
get_map_lst.c get_map.c check_map.c

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c &< -o $@

${NAME}: 	${OBJ}
			make -C ./mlx
			${CC} -g -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJ} libmlx.a ./libft/libft.a -o ${NAME}

all: ${NAME}
