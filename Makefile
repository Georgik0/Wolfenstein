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

OBJ = start_game.c draw_ray.c find_block_unique.c find_collision.c \
find_block_horisontal.c find_block_vertical.c draw_3d.c get_length.c

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c &< -o $@

${NAME}: 	${OBJ}
			make -C ./mlx
			${CC} -g -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJ} libmlx.a ./libft/libft.a -o ${NAME}

all: ${NAME}
