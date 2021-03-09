/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dx_dy_ax_ay.c                                  :+:      :+:    :+:   */
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

int		get_ax(t_player player, double phi)
{
	int ax;

	if (phi == M_PI / 2 || phi == 3 * M_PI / 2)
		ax = player.x;
	else if (phi == 0)
		ax = (player.x / 64) * 64 + 64;
	else
		ax = (player.x / 64) * 64 - 1;
	return (ax);
}

int		get_ay(t_player player, double phi)
{
	int	ay;

	if (phi == 0 || phi == M_PI)
		ay = player.y;
	else if (phi == M_PI / 2)
		ay = (player.y / 64) * 64 - 1;
	else
		ay = (player.y / 64) * 64 + 64;
	return (ay);
}
