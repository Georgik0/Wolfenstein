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

int			get_around_Ax(double Ax, double phi)
{
	if (phi > M_PI && phi < 3 * M_PI / 2)
	{
		if (Ax - (int)Ax / 64 * 64 >= 63)
			return ((int)Ax / 64 + 1);
	}
	if (phi > 3 * M_PI / 2 && phi < 2 * M_PI)
	{
		if (Ax - (int)Ax / 64 * 64 >= 63)
			return ((int)Ax / 64);
	}
	if (phi > 0 && phi < M_PI / 2)
	{
		if (Ax - (int)Ax / 64 * 64 >= 63)
			return ((int)Ax / 64);
	}
	if (phi > M_PI / 2 && phi < M_PI)
	{
		if (Ax - (int)Ax / 64 * 64 >= 63)
			return ((int)Ax / 64 + 1);
	}
	return (Ax / 64);//((int)nearbyint(Ax) / 64);
}

// t_collis	collision_width_horisontal(char (*map)[10], t_coord_horis horis, double phi) //double dx, double dy, double Ax, double Ay
// {
// 	int			y;
// 	int			x;
// 	t_collis	collis;

// 	y = (int)(horis.Ay / 64);
// 	// x = get_around_Ax(horis.Ax, phi);
// 	x = (int)(horis.Ax / 64);
// 	// printf("horis y = %d | x = %d\n", y, x);
// 	// printf("-----------horiz-----------\n");
// 	// printf("Ax1 = %f   Ay1 = %d\n", horis.Ax, horis.Ay);
// 	while (y >= 0 && x >= 0 && y < 10 && x < 10 && map[y][x] != '1')
// 	{
// 		horis.Ax += horis.dx;
// 		horis.Ay += horis.dy;
// 		// printf("Ax = %f   Ay = %d\n", horis.Ax, horis.Ay);
// 		y = (int)(horis.Ay / 64);
// 		// x = get_around_Ax(horis.Ax, phi);
// 		x = (int)(horis.Ax / 64);
// 	}
// 	// printf("horis y = %d | x = %d\n", y, x);
// 	collis.x = (int)(horis.Ax);
// 	// collis.x = get_around_Ax(horis.Ax, phi);
// 	collis.y = (int)(horis.Ay);
// 	// printf("horis collis.x = %d   collis.y = %d\n", collis.x, collis.y);
// 	// printf("-----------horiz-----------\n");
// 	return (collis);
// }

// t_collis	find_block_horisontal(t_player player, char (*map)[10], double phi)
// {
// 	t_coord_horis	horis;
// 	t_collis		collis;

// 	if (phi < M_PI)
// 	{
// 		horis.Ay = (int)((player.y / 64) * 64) - 1;
// 		horis.dy = -64;
// 	}
// 	else // phi > M_PI
// 	{
// 		horis.Ay = (int)((player.y / 64) * 64) + 64;
// 		horis.dy = 64;
// 	}
// 	horis.Ax = player.x + (player.y - horis.Ay) / tan(phi) + 1;
// 	if (phi > M_PI)
// 		horis.dx = -64.0 / tan(phi);
// 	else
// 		horis.dx = 64.0 / tan(phi);
// 	collis = collision_width_horisontal(map, horis, phi);
// 	return (collis);
// }

t_collis	collision_width_horisontal(char (*map)[10], t_coord_horis horis, double phi, t_player player, t_sprite **sprite)
{
	int			y;
	int			x;
	t_collis	collis;

	y = (int)nearbyint(horis.Ay) / 64;
	x = get_around_Ax(horis.Ax, phi);
	// x = (int)nearbyint(horis.Ax) / 64;
	// printf("-----------horiz-----------\n");
	// printf("Ax1 = %f   Ay1 = %d          x = %d  y = %d\n", horis.Ax, horis.Ay, x, y);
	while (y >= 0 && x >= 0 && y < 10 && x < 10 && map[y][x] != '1')
	{
		if (map[y][x] == '2')
		{
			if (add_sprite(sprite, x * 64 - 32, y * 64 - 32, player) == 0)
			{
				collis.err = 1;
				return (collis);
			}
		}
		horis.Ax += horis.dx;
		horis.Ay += horis.dy;
		// printf("Ax = %f   Ay = %d\n", horis.Ax, horis.Ay);
		y = (int)(nearbyint(horis.Ay) / 64);
		// x = (int)(nearbyint(horis.Ax) / 64);
		x = get_around_Ax(horis.Ax, phi);
	}
	// printf("horis Ay = %d | Ax = %f\n", horis.Ay, horis.Ax);
	// collis.x = (int)nearbyint(horis.Ax);
	// collis.y = (int)nearbyint(horis.Ay);
	collis.x = horis.Ax;
	collis.y = horis.Ay;
	collis.offset = (horis.Ax - (int)(horis.Ax / 64) * 64) / 64;
	// printf("x = %f    y = %f   offset = %f\n", collis.x, collis.y, collis.offset);
	// printf("-----------horiz-----------\n");
	return (collis);
}

t_collis	find_block_horisontal(t_player player, char (*map)[10], double phi, t_sprite **sprite)
{
	t_coord_horis	horis;
	t_collis		collis;

	if (phi < M_PI)
	{
		horis.Ay = (int)((player.y / 64) * 64) - 1;
		horis.dy = -64;
	}
	else // phi > M_PI
	{
		horis.Ay = (int)((player.y / 64) * 64) + 64;
		horis.dy = 64;
	}
	horis.Ax = player.x + (player.y - horis.Ay) / tan(phi);
	if (phi > M_PI)
		horis.dx = -64.0 / tan(phi);
	else
		horis.dx = 64.0 / tan(phi);
	collis = collision_width_horisontal(map, horis, phi, player, sprite);
	return (collis);
}
