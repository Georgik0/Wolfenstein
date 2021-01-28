/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:58:17 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/25 19:58:23 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"
#include "mlx/mlx.h"

static double		get_distance(t_player player, double x1, double y1, double phi) //(double x0, double x1, double phi)
{
	double	distance;

	distance = sqrt((player.x - x1) * (player.x - x1) + (player.y - y1) * (player.y - y1)) * fabs(cos(phi));
	if (isnan(distance))
		distance = INFINITY;
	return (distance);
	// double	distance;

	// distance = (x0 - x1) / cos(phi);
	// if (distance <= 0)
	// 	return (-distance);
	// return (distance);
}

static double		get_distance_unique(t_collis collis, t_player player)
{
	double	distance;

	distance = ft_abs(collis.x - player.x) + ft_abs(collis.y - player.y);
	return (distance);
}

static double		compare_distance(t_collis horisont, t_collis vertical, t_player player, double phi)
{
	double	distance_h;
	double	distance_v;

	distance_h = get_distance(player, horisont.x, horisont.y, phi);
	distance_v = get_distance(player, vertical.x, vertical.y, phi);
	if (distance_v > distance_h)
		return (distance_h);
	return (distance_v);
}

int					get_length(double phi, t_player player, char (*map)[10])
{
	int				length;
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;

	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
	{
		collis = find_block_unique(phi, player, map);
		length = (int)nearbyint(get_distance_unique(collis, player));
	}
	else
	{
		horisont = find_block_horisontal(player, map, phi);
		vertical = find_block_vertical(player, map, phi);
		length = (int)nearbyint(compare_distance(horisont, vertical, player, phi));
	}
	return (length);
}
