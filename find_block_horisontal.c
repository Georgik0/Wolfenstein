/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_horisontal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:14:29 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/14 13:14:32 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

t_collis	collision_width_horisontal(char map[][10], t_coord_horis horis) //double dx, double dy, double Ax, double Ay
{
	int			y;
	int			x;
	t_collis	collis;

	y = (int)nearbyint(horis.Ay) / 64;
	x = (int)nearbyint(horis.Ax) / 64;
	while (map[y][x] != '1')
	{
		horis.Ax += horis.dx;
		horis.Ay += horis.dy;
		y = (int)nearbyint(horis.Ay) / 64;
		x = (int)nearbyint(horis.Ax) / 64;
	}
	collis.x = (int)nearbyint(horis.Ax);
	collis.y = (int)nearbyint(horis.Ay);
	return (collis);
}

t_collis	find_block_horisontal(t_player player, char map[][10], double phi)
{
	t_coord_horis	horis;
	t_collis		collis;

	if (phi < M_PI)
	{
		horis.Ay = (player.y / 64) * 64 - 1;
		horis.dy = -64;
	}
	else // phi > M_PI
	{
		horis.Ay = (player.y / 64) * 64 + 64;
		horis.dy = 64;
	}
	horis.Ax = player.x + (player.y - horis.Ay) / tan(phi);
	horis.dx = 64 / tan(phi);
	collis = collision_width_horisontal(map, horis);
	return (collis);
}
