/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_horisontal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:28:54 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:28:58 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int			get_around_ax(double a_x, double phi)
{
	if (phi > M_PI && phi < 3 * M_PI / 2)
	{
		if (a_x - (int)a_x / 64 * 64 >= 63)
			return ((int)a_x / 64 + 1);
	}
	if (phi > 3 * M_PI / 2 && phi < 2 * M_PI)
	{
		if (a_x - (int)a_x / 64 * 64 >= 63)
			return ((int)a_x / 64);
	}
	if (phi > 0 && phi < M_PI / 2)
	{
		if (a_x - (int)a_x / 64 * 64 >= 63)
			return ((int)a_x / 64);
	}
	if (phi > M_PI / 2 && phi < M_PI)
	{
		if (a_x - (int)a_x / 64 * 64 >= 63)
			return ((int)a_x / 64 + 1);
	}
	return (a_x / 64);
}

t_collis	collision_width_horisontal(t_coord_horis horis, double phi,
t_vars *vars, t_sprite **sp)
{
	t_xy_data	xy;
	t_collis	collis;

	xy.y = (int)nearbyint(horis.ay) / 64;
	xy.x = get_around_ax(horis.ax, phi);
	while (xy.y >= 0 && xy.x >= 0 && xy.y < vars->length_map_y && xy.x <
	ft_strlen(vars->map[xy.y]) && vars->map[xy.y][xy.x] != '1')
	{
		if (vars->map[xy.y][xy.x] == '2')
		{
			if (!add_sprite(sp, xy.x * 64 + 32, xy.y * 64 + 32, vars->player))
			{
				collis.err = 1;
				return (collis);
			}
		}
		horis.ax += horis.dx;
		horis.ay += horis.dy;
		xy.y = (int)(nearbyint(horis.ay) / 64);
		xy.x = get_around_ax(horis.ax, phi);
	}
	collis.x = horis.ax;
	collis.y = horis.ay;
	collis.offset = (horis.ax - (int)(horis.ax / 64) * 64) / 64;
	return (collis);
}

t_collis	find_block_horisontal(t_vars *vars, double phi, t_sprite **sprite)
{
	t_coord_horis	horis;
	t_collis		collis;

	if (phi < M_PI)
	{
		horis.ay = (int)((vars->player.y / 64) * 64) - 1;
		horis.dy = -64;
	}
	else
	{
		horis.ay = (int)((vars->player.y / 64) * 64) + 64;
		horis.dy = 64;
	}
	horis.ax = vars->player.x + (vars->player.y - horis.ay) / tan(phi);
	if (phi > M_PI)
		horis.dx = -64.0 / tan(phi);
	else
		horis.dx = 64.0 / tan(phi);
	collis = collision_width_horisontal(horis, phi, vars, sprite);
	return (collis);
}
