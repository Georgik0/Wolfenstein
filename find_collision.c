/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:34 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:30:36 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

static double		get_distance(t_player player, double x1, double y1, double phi)
{
	double	distance;

	distance = sqrt((player.x - x1) * (player.x - x1) + (player.y - y1) * (player.y - y1)) * fabs(cos(phi));
	if (isnan(distance))
		distance = INFINITY;
	return (distance);
}

t_collis	compare_collision(t_collis horisont, t_collis vertical, t_player player, double phi)
{
	double	distance_h;
	double	distance_v;

	distance_h = get_distance(player, horisont.x, horisont.y, phi);
	distance_v = get_distance(player, vertical.x, vertical.y, phi);
	if (distance_v > distance_h)
		return (horisont);
	return (vertical);
}

t_collis	find_collision(double phi, t_vars *vars)
{
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;
	t_sprite		*sprite;

	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
		collis = find_block_unique(phi, vars, NULL);
	else
	{
		horisont = find_block_horisontal(vars, phi, NULL);
		vertical = find_block_vertical(vars, phi, NULL);
		collis = compare_collision(horisont, vertical, vars->player, phi);
	}
	return (collis);
}
