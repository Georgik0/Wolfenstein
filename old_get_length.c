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

static double		get_distance(t_player player, double x1, double y1, double phi, double pov) //(double x0, double x1, double phi)
{
	double	distance;

	distance = sqrt((player.x - x1) * (player.x - x1) + (player.y - y1) * (player.y - y1)) * fabs(cos(phi - pov));
	// distance = fabs((x1 - player.x) * cos(phi)) * fabs(cos(phi - pov));
	// printf("distance = %f\n", distance);
	if (isnan(distance))
		return(INFINITY);
	return (distance);
	// double	distance;

	// distance = (x0 - x1) / cos(phi);
	// if (distance <= 0)
	// 	return (-distance);
	// return (distance);
}

static t_data_draw		get_distance_unique(t_collis collis, t_player player, double phi)
{
	t_data_draw	data_draw;

	data_draw.length = ft_abs(collis.x - player.x) + ft_abs(collis.y - player.y);
	if (phi == 0)
		data_draw.color = 0xFF8C00;
	else if (phi == M_PI / 2)
		data_draw.color = 0xEE82EE;
	else if (phi == M_PI)
		data_draw.color = 0x9ACD32;
	else
		data_draw.color = 0xFFEFD5;
	return (data_draw);
	// return (data_draw.length);
}

static t_data_draw		compare_distance(t_collis horisont, t_collis vertical, t_player player, double phi, double pov)
{
	double			distance_h;
	double			distance_v;
	t_data_draw		data_draw;

	distance_h = get_distance(player, horisont.x, horisont.y, phi, pov);
	distance_v = get_distance(player, vertical.x, vertical.y, phi, pov);
	if (distance_v > distance_h)
	{
		if (phi < M_PI)
			data_draw.color = 0xEE82EE;
		else
			data_draw.color = 0xFFEFD5;
		data_draw.length = distance_h;
		return (data_draw);
		// return (distance_h);
	}
	if (phi < M_PI / 2 || phi > 3 * M_PI / 2)
		data_draw.color = 0xFF8C00;
	else
		data_draw.color = 0x9ACD32;
	data_draw.length = distance_v;
	return (data_draw);
	// return (distance_v);
}

t_data_draw			get_length(int pov, double phi, t_player player, char (*map)[10])
{
	t_data_draw		data_draw;
	double			length;
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;

	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
	{
		collis = find_block_unique(phi, player, map);
		data_draw = get_distance_unique(collis, player, phi);
		// length = get_distance_unique(collis, player, phi);
	}
	else
	{
		horisont = find_block_horisontal(player, map, phi);
		vertical = find_block_vertical(player, map, phi);
		data_draw = compare_distance(horisont, vertical, player, phi, pov * M_PI / 180);
		// length = compare_distance(horisont, vertical, player, phi, pov * M_PI / 180);
	}
	return (data_draw);
	// return (length);
}
