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

#include <stdio.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

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

}				t_player;

typedef struct	s_collis
{
	int			x;
	int			y;

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
	float		Ax;
	int			Ay;
	float		dx;
	int			dy;

}				t_coord_horis;

typedef struct	s_coord_vertic
{
	int			Bx;
	float		By;
	int			dx;
	float		dy;

}				t_coord_vertic;

typedef struct  s_vars
{
	void		*mlx;
	void		*win;
	t_player	*player;

}				t_vars;


t_collis	find_collision(double phi, t_player player, char map[][10]);
t_collis	find_block_unique(double phi, t_player player, char map[][10]);
t_collis	find_block_horisontal(t_player player, char map[][10], float phi);
t_collis	find_block_vertical(t_player player, char map[][10], float phi);
void		print_line(int x0, int y0, int x1, int y1, t_data *img);
void		draw_ray(double pov, t_player player, char map[][10], t_data *img);


#endif
