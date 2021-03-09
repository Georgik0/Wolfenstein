/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_unique.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:29:34 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:29:36 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

t_collis	get_collis(t_coord_uniq coord, t_vars *vars, t_sprite **sprite)
{
	int			x;
	int			y;
	t_collis	collis;

	x = coord.ax / 64;
	y = coord.ay / 64;
	while (vars->map[y][x] != '1')
	{
		if (vars->map[y][x] == '2')
		{
			if (add_sprite(sprite, x * 64 + 32, y * 64 + 32, vars->player) == 0)
			{
				collis.err = 1;
				return (collis);
			}
		}
		coord.ax += coord.dx;
		coord.ay += coord.dy;
		x = coord.ax / 64;
		y = coord.ay / 64;
	}
	collis.x = coord.ax;
	collis.y = coord.ay;
	return (collis);
}

t_collis	find_block_unique(double phi, t_vars *vars, t_sprite **sprite)
{
	t_coord_uniq	coord;
	t_collis		collis;

	coord.ax = get_ax(vars->player, phi);
	coord.ay = get_ay(vars->player, phi);
	coord.dx = get_dx(phi);
	coord.dy = get_dy(phi);
	collis = get_collis(coord, vars, sprite);
	if (phi == 0 || phi == M_PI)
		collis.offset = vars->player.y % 64 / 64.0;
	else
		collis.offset = vars->player.x % 64 / 64.0;
	return (collis);
}
