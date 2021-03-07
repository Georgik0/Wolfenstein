/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dx_dy_Ax_Ay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:31:10 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 18:31:11 by skitsch          ###   ########.fr       */
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
