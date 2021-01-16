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
	// printf("horis y = %d | x = %d\n", y, x);
	while (y >= 0 && x >= 0 && y < 10 && x < 10 && map[y][x] != '1')
	{
		horis.Ax += horis.dx;
		horis.Ay += horis.dy;
		y = (int)nearbyint(horis.Ay) / 64;
		x = (int)nearbyint(horis.Ax) / 64;
	}
	// printf("horis y = %d | x = %d\n", y, x);
	collis.x = (int)nearbyint(horis.Ax);
	collis.y = (int)nearbyint(horis.Ay);
	// printf("horis collis.x = %d   collis.y = %d\n", collis.x, collis.y);
	return (collis);
}

t_collis	find_block_horisontal(t_player player, char map[][10], float phi)
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
	if (phi > M_PI)
		horis.dx = -64 / tan(phi);
	else
		horis.dx = 64 / tan(phi);
	collis = collision_width_horisontal(map, horis);
	// if (horis.dx > 0)
	// {
		// printf("градусы phi = %f   M_PI/2 = %f   dx = %f   tan(phi) = %f\n", phi * 180 / M_PI, M_PI / 2, horis.dx, tan(phi));
	// }
	return (collis);
}
