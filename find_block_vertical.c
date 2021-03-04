/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:03 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:30:05 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int			get_around_By(double By, double phi)
{
	if (phi > M_PI && phi < 3 * M_PI / 2)
	{
		if (By - (int)By / 64 * 64 >= 63)
			return ((int)By / 64);
	}
	if (phi > 3 * M_PI / 2 && phi < 2 * M_PI)
	{
		if (By - (int)By / 64 * 64 >= 63)
			return ((int)By / 64);
	}
	if (phi > 0 && phi < M_PI / 2)
	{
		if (By - (int)By / 64 * 64 >= 63)
			return ((int)By / 64 + 1);
	}
	if (phi > M_PI / 2 && phi < M_PI)
	{
		if (By - (int)By / 64 * 64 >= 63)
			return ((int)By / 64 + 1);
	}
	return (By / 64);//((int)nearbyint(By) / 64);
}

// t_collis	collision_width_vertical(char (*map)[10], t_coord_vertic vertic, double phi) //double dx, double dy, double Ax, double Ay
// {
// 	int			y;
// 	int			x;
// 	t_collis	collis;

// 	y = (int)(vertic.By / 64);
// 	// y = get_around_By(vertic.By, phi);
// 	x = (int)(vertic.Bx / 64);
// 	// printf("vertic y = %d | x = %d\n", y, x);
// 	// printf("-----------vertic-----------\n");
// 	// printf("Bx1 = %d   By1 = %f\n", vertic.Bx, vertic.By);
// 	while (y >= 0 && x >= 0 && y < 10 && x < 10 && map[y][x] != '1')
// 	{
// 		vertic.Bx += vertic.dx;
// 		vertic.By += vertic.dy;
// 		// printf("Bx = %d   By = %f\n", vertic.Bx, vertic.By);
// 		y = (int)(vertic.By / 64);
// 		// y = get_around_By(vertic.By, phi);
// 		x = (int)(vertic.Bx / 64);
// 	}
// 	// printf("vertic y = %d | x = %d\n", y, x);
// 	collis.x = (int)(vertic.Bx);
// 	collis.y = (int)(vertic.By);
// 	// printf("vertic collis.x = %d   collis.y = %d\n", collis.x, collis.y);
// 	// printf("-----------vertic-----------");
// 	return (collis);
// }

// t_collis	find_block_vertical(t_player player, char (*map)[10], double phi)
// {
// 	t_coord_vertic	vertic;
// 	t_collis		collis;

// 	if (phi > 3 * M_PI / 2 || phi < M_PI / 2)
// 	{
// 		vertic.Bx = (int)((player.x / 64) * 64) + 64;
// 		vertic.dx = 64;
// 	}
// 	else // phi > M_PI / 2 && phi < 3 * M_PI / 2
// 	{
// 		vertic.Bx = (int)((player.x / 64) * 64) - 1;
// 		vertic.dx = -64;
// 	}
// 	vertic.By = player.y + (player.x - vertic.Bx) * tan(phi);
// 	if ((phi > 0 && phi < M_PI / 2) || phi > 3 * M_PI / 2)
// 	{
// 		vertic.dy = -64.0 * tan(phi);
// 	}
// 	else
// 		vertic.dy = 64.0 * tan(phi);
// 	// printf("By = %f Bx = %d\n", vertic.By, vertic.Bx);
// 	collis = collision_width_vertical(map, vertic, phi);
// 	return (collis);
// }

t_collis	collision_width_vertical(char (*map)[10], t_coord_vertic vertic, double phi, t_vars *vars, t_sprite **sprite)
{
	int			y;
	int			x;
	t_collis	collis;

	y = get_around_By(vertic.By, phi);
	x = (int)nearbyint(vertic.Bx) / 64;
	while (y >= 0 && x >= 0 && y < vars->length_map_y && x < ft_strlen(vars->map[y]) - 1 && vars->map[y][x] != '1')
	{
		if (vars->map[y][x] == '2')
		{
			if (add_sprite(sprite, x * 64 + 32, y * 64 + 32, vars->player) == 0)
			{
				collis.err = 1;
				return (collis);
			}
		}
		vertic.Bx += vertic.dx;
		vertic.By += vertic.dy;
		y = get_around_By(vertic.By, phi);
		x = (int)(nearbyint(vertic.Bx) / 64);
	}
	collis.x = vertic.Bx;
	collis.y = vertic.By;
	collis.offset = (vertic.By - (int)(vertic.By / 64) * 64) / 64;
	return (collis);
}

t_collis	find_block_vertical(t_vars *vars, char (*map)[10], double phi, t_sprite **sprite)
{
	t_coord_vertic	vertic;
	t_collis		collis;

	if (phi > 3.0 * M_PI / 2.0 || phi < M_PI / 2.0)
	{
		vertic.Bx = (int)((vars->player.x / 64) * 64) + 64;
		vertic.dx = 64;
	}
	else // phi > M_PI / 2 && phi < 3 * M_PI / 2
	{
		vertic.Bx = (int)((vars->player.x / 64) * 64) - 1;
		vertic.dx = -64;
	}
	vertic.By = vars->player.y + (vars->player.x - vertic.Bx) * tan(phi);
	if ((phi > 0.0 && phi < M_PI / 2.0) || phi > 3.0 * M_PI / 2.0)
	{
		vertic.dy = -64.0 * tan(phi);
	}else
		vertic.dy = 64.0 * tan(phi);
	collis = collision_width_vertical(map, vertic, phi, vars, sprite);
	return (collis);
}
