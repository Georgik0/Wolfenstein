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

OBJ = start_game.c

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c &< -o $@

${NAME}: 	${OBJ}
			make -C ./mlx
			${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJ} libmlx.a -o ${NAME}

all: ${NAME}
