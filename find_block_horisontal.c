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

double		get_dx(double phi)
{
	double dx;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
	{
		dx = 0;
	}
	else if (phi == 0)
	{
		dx = 64;
	}
	else if (phi == M_PI)
	{
		dx = -64;
	}
	else
	{
		dx = 64 / tan(phi);
	}
	return (dx);
}

double		get_dy(double phi)
{
	double dy;

	if (phi == 0 || phi == M_PI)
	{
		dy = 0;
	}
	else if (phi == M_PI / 2)
	{
		dy = -64;
	}
	else if (phi == 3 * M_PI / 2)
	{
		dy = 64;
	}
	else
	{
		dy = 64 / tan(phi);
	}
	return (dy);
}

double		get_Ax(double phi, int player_x, int player_y, int Ay)
{
	double Ax;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
	{
		Ax = player_x;
	}
	else if (phi == 0)
	{
		Ax = player_x + (player_y - Ay) / tan(phi);
	}

}

int		horizontal_line(int player_x, int player_y, double phi)
{
	int Ax;
// 0 или pi
	if (phi == 0)
		Ax = (player_x / 64) * 64 + 64;
	else
		Ax = (player_x / 64) * 64 - 1;
	return (Ax);
}

int		vertical_line(int player_x, int player_y, double phi)
{
	int Ay;
// pi/2 или 3/2 * pi
	if (phi == M_PI / 2)
		Ay = (player_x / 64) * 64 - 1;
	else
		Ay = (player_x / 64) * 64 + 64;
	return (Ay);
}

double		collision_width_vertical()
{

}

t_coord		collision_width_horisontal(char map[][10], double dx, double dy, double Ax, double Ay)
{
	int		y;
	int		x;
	t_coord	coord;

	y = (int)nearbyint(Ay) / 64;
	x = (int)nearbyint(Ax) / 64;
	while (map[y][x] != '1')
	{
		Ax += dx;
		Ay += dy;
		y = (int)nearbyint(Ay) / 64;
		x = (int)nearbyint(Ax) / 64;
	}
	coord.wall_horis_x = (int)nearbyint(Ax);
	coord.wall_horis_y = (int)nearbyint(Ay);
	return (coord);
}

void	find_block_horisontal(int player_x, int player_y, char map[][10], double phi)
{
	int dy;
	double dx;
	double Ax;
	int Ay;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
	{
		Ay = vertical_line(player_x, player_y, phi);
		Ax = player_x;
	}
	else if (phi == 0 || phi == M_PI)
	{
		Ay = player_y;
		Ax = horizontal_line(player_x, player_y, phi);
	}
	else if (phi < M_PI)
	{
		Ay = (player_y / 64) * 64 - 1;
		dy = -64;
	}
	else if (phi > M_PI)
	{
		Ay = (player_y / 64) * 64 + 64;
		dy = 64;
	}
	dy = get_dy(phi);
	dx = get_dx(phi);
}
