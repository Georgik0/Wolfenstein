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

int		get_dx(double phi)
{
	int	dx;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
		dx = 0;
	else if (phi == 0)
		dx = 64;
	else
		dx = -64;
	return (dx);
}

int		get_dy(double phi)
{
	int	dy;

	if (phi == 0 || phi == M_PI)
		dy = 0;
	else if (phi == M_PI / 2)
		dy = -64;
	else
		dy = 64;
	return (dy);
}

int		get_Ax(t_player player, double phi)
{
	int Ax;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
		Ax = player.x;
	else if (phi == 0)
		Ax = (player.x / 64) * 64 + 64;
	else
		Ax = (player.x / 64) * 64 - 1;
	return (Ax);
}

int		get_Ay(t_player player, double phi)
{
	int	Ay;

	if (phi == 0 || phi == M_PI)
		Ay = player.y;
	else if (phi == M_PI / 2)
		Ay = (player.y / 64) * 64 - 1;
	else
		Ay = (player.y / 64) * 64 + 64;
	return (Ay);
}

t_collis	get_collis(t_coord_uniq coord, char (*map)[10])
{
	int			x;
	int			y;
	t_collis	collis;

	x = coord.Ax / 64;
	y = coord.Ay / 64;
	while (map[y][x] != '1')
	{
		coord.Ax += coord.dx;
		coord.Ay += coord.dy;
		x = coord.Ax / 64;
		y = coord.Ay / 64;
	}
	collis.x = coord.Ax;
	collis.y = coord.Ay;
	return (collis);
}

t_collis	find_block_unique(double phi, t_player player, char (*map)[10])
{
	t_coord_uniq	coord;
	t_collis		collis;

	coord.Ax = get_Ax(player, phi);
	coord.Ay = get_Ay(player, phi);
	coord.dx = get_dx(phi);
	coord.dy = get_dy(phi);
	collis = get_collis(coord, map);
	if (phi == 0 || phi == M_PI)
		collis.offset = player.y % 64 / 64.0;
	else
		collis.offset = player.x % 64 / 64.0;
	return (collis);
}
