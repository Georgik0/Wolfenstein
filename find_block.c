/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:14:38 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/13 19:14:40 by skitsch          ###   ########.fr       */
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

double		horizontal_line(int player_x, int player_y)
{

}

double		vertical_line(int player_x, int player_y)
{

}

void	find_block(int player_x, int player_y, char map[][10], double phi)
{
	int dy;
	double dx;
	double Ax;
	int Ay;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
	{

	}
	else if (phi == 0 || phi == M_PI)
	{

	}


	if (phi < M_PI)
	{
		Ay = (player_y / 64) * 64 - 1;
		dy = -64;
	}
	else if (phi > M_PI)
	{
		Ay = (player_y / 64) * 64 + 64;
		dy = 64;
	}
	Ax = player_x + (player_y - Ay) / tan(phi);
	dx = get_dx(phi);
}
