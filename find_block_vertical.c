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

t_collis	collision_width_vertical(char (*map)[11], t_coord_vertic vertic) //double dx, double dy, double Ax, double Ay
{
	int			y;
	int			x;
	t_collis	collis;

	y = (int)nearbyint(vertic.By) / 64;
	x = (int)nearbyint(vertic.Bx) / 64;
	// printf("vertic y = %d | x = %d\n", y, x);
	while (y >= 0 && x >= 0 && y < 10 && x < 10 && map[y][x] != '1')
	{
		vertic.Bx += vertic.dx;
		vertic.By += vertic.dy;
		y = (int)nearbyint(vertic.By) / 64;
		x = (int)nearbyint(vertic.Bx) / 64;
	}
	// printf("vertic y = %d | x = %d\n", y, x);
	collis.x = (int)nearbyint(vertic.Bx);
	collis.y = (int)nearbyint(vertic.By);
	// printf("vertic collis.x = %d   collis.y = %d\n", collis.x, collis.y);
	return (collis);
}

t_collis	find_block_vertical(t_player player, char (*map)[11], float phi)
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
	if ((phi > 0 && phi < M_PI / 2) || phi > 3 * M_PI / 2)
	{
		vertic.dy = -64 * tan(phi);
	}else
		vertic.dy = 64 * tan(phi);
	// printf("player.y = %d\nplayer.x = = %d\nvertic.Bx = = %d\nvertic.By = = %f\nphi = %f\ndy = %f\ntan(phi) = %f\n", player.y, player.x, vertic.Bx, vertic.By , phi * 180 / M_PI, vertic.dy, tan(phi));
	// printf("By = %f Bx = %d\n", vertic.By, vertic.Bx);
	// if (vertic.dy > 0)
	// {
	// 	printf("градусы phi = %f   M_PI/2 = %f   dy = %f   tan(phi) = %f  радиан phi = %f\n", phi * 180 / M_PI, M_PI / 2, vertic.dy, tan(phi), phi);
	// }
	collis = collision_width_vertical(map, vertic);
	return (collis);
}
