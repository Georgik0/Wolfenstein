/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:13:22 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/08 18:14:39 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPE_H
# define MY_TYPE_H
#include <math.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"

#include <stdio.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	double		d;

}				t_data;

typedef struct	s_coord
{
	int			wall_horis_x;
	int			wall_horis_y;
	int			wall_vertical_x;
	int			wall_vertical_y;
	int			collis_x;
	int			collis_y;

}				t_coord;

typedef struct	s_player
{
	int			x;
	int			y;
	double		pov;

}				t_player;

typedef struct	s_list_sprite
{
	double		x;
	double		y;
	double
}				t_list_sprite;


typedef struct	s_collis
{
	double		x;
	double		y;
	double		offset;

}				t_collis;

typedef struct	s_coord_uniq
{
	int			Ax;
	int			Ay;
	int			dx;
	int			dy;

}				t_coord_uniq;

typedef struct	s_coord_horis
{
	double		Ax;
	double		Ay;
	double		dx;
	double		dy;

}				t_coord_horis;

typedef struct	s_coord_vertic
{
	double		Bx;
	double		By;
	double		dx;
	double		dy;

}				t_coord_vertic;

typedef struct	s_data_map
{
	int			map_len_x;
	int			map_len_y;
	int			size_cub;
	char		(*map)[10];

}				t_data_map;

typedef struct	s_data_draw
{
	char		side;
	double		length;
	double		offset;

}				t_data_draw;


typedef struct	s_keyboard
{
	int			A;
	int			D;
	int			W;
	int			S;
	int			left;
	int			right;

}				t_keyboard;


typedef struct  s_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_data		*data;
	t_data_map	data_map;
	t_keyboard	keyboard;
	t_data		**data_array;

}				t_vars;


t_collis		find_collision(double phi, t_player player, char (*map)[10]);
t_collis		find_block_unique(double phi, t_player player, char (*map)[10]);
t_collis		find_block_horisontal(t_player player, char (*map)[10], double phi);
t_collis		find_block_vertical(t_player player, char (*map)[10], double phi);
void			print_line(int x0, int y0, int x1, int y1, t_data *img);
void			draw_ray(double pov, t_player player, char (*map)[10], t_data *img);
t_data_draw		get_length(int pov, double phi, t_player player, char (*map)[10]);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_3d(int pov, t_player player, char (*map)[10], t_data *data, t_data **data_array);
unsigned int	get_color(t_data data, int y, double offset, int h);

#endif
