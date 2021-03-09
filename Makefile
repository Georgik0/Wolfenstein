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

SRC = start_game.c find_block_unique.c find_collision.c \
find_block_horisontal.c find_block_vertical.c draw_3d.c get_length.c \
put_pixel_texture.c get_sprite.c draw_sprite.c get_calc.c get_next_line.c \
get_next_line_utils.c parser.c get_param.c get_screen_param.c \
get_texture.c get_texture_1.c make_malloc_vars.c get_floor_and_celling.c \
get_map_lst.c get_map.c check_map.c make_screenshot.c get_img.c change_a_d.c \
change_coord.c change_keyboard.c draw_world.c get_dx_dy_ax_ay.c \
reading_file.c work_with_input_lst.c error_processing.c check_wall.c \
clear_param.c get_width_height.c

OBJ = ${SRC:.c=.o}

HEADERS = ./header/my_type.h ./header/get_next_line.h

LIBFTDIR = ./libft

MLXDIR = ./mlx

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MAKE = make -C

MAKES = makes

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm

%.o: %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJ} ${HEADERS}
			make -C ${LIBFTDIR}
			make -C ${MLXDIR}
			${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJ} ./mlx/libmlx.a ./libft/libft.a -o ${NAME}

all: ${NAME}

bonus: ${NAME}

clean:
	${MAKE} ${LIBFTDIR} clean
	${RM} -f ${OBJ}

fclean: clean
	${MAKE} ${LIBFTDIR} fclean
	${RM} -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
