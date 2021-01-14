/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:33:56 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/14 18:33:57 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

t_collis	collision_width_vertical(char map[][10], t_coord_vertic vertic) //double dx, double dy, double Ax, double Ay
{
	int			y;
	int			x;
	t_collis	collis;

	y = (int)nearbyint(vertic.By) / 64;
	x = (int)nearbyint(vertic.Bx) / 64;
	while (map[y][x] != '1')
	{
		vertic.Bx += vertic.dx;
		vertic.By += vertic.dy;
		y = (int)nearbyint(vertic.By) / 64;
		x = (int)nearbyint(vertic.Bx) / 64;
	}
	collis.x = (int)nearbyint(vertic.Bx);
	collis.y = (int)nearbyint(vertic.By);
	return (collis);
}

t_collis	find_block_vertical(t_player player, char map[][10], double phi)
{
	t_coord_vertic	vertic;
	t_collis		collis;

	if (phi > 3 * M_PI / 2 || phi < M_PI / 2)
	{
		vertic.Bx = (player.x / 64) * 64 + 64;
		vertic.dx = 64;
	}
	else // phi > M_PI / 2 && phi < 3 * M_PI / 2
	{
		vertic.Bx = (player.x / 64) * 64 - 1;
		vertic.dx = -64;
	}
	vertic.By = player.y + (player.x - vertic.Bx) * tan(phi);
	vertic.dy = 64 * tan(phi);
	collis = collision_width_vertical(map, vertic);
	return (collis);
}
