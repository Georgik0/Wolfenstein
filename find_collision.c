/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:16:14 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/14 13:16:17 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

float		get_distance(int x0, int x1, double phi)
{
	float	distance;

	distance = (x0 - x1) / cos(phi);
	return (distance);
}

t_collis	compare_collision(t_collis horisont, t_collis vertical, t_player player, double phi)
{
	float	distance_h;
	float	distance_v;

	distance_h = get_distance(player.x, horisont.x, phi);
	distance_v = get_distance(player.x, vertical.x, phi);
	if (fabs(distance_v) > fabs(distance_h))
		return (horisont);
	return (vertical);
}

t_collis	find_collision(double phi, t_player player, char (*map)[10])
{
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;

	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
	{
		collis = find_block_unique(phi, player, map);
	}
	else
	{
		horisont = find_block_horisontal(player, map, phi);
		vertical = find_block_vertical(player, map, phi);
		collis = compare_collision(horisont, vertical, player, phi);
	}
	return (collis);
}
