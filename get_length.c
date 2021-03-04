/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:31:09 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:31:11 by skitsch          ###   ########.fr       */
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
	data_draw.offset = collis.offset;
	if (phi == 0)
		data_draw.side = 'r';//0xFF8C00;
	else if (phi == M_PI / 2)
		data_draw.side = 'u';//0xEE82EE;
	else if (phi == M_PI)
		data_draw.side = 'l';//0x9ACD32;
	else
		data_draw.side = 'd';//0xFFEFD5;
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
			data_draw.side = 'u';//0xEE82EE;
		else
			data_draw.side = 'd';//0xFFEFD5;
		data_draw.length = distance_h;
		data_draw.offset = horisont.offset;
		return (data_draw);
		// return (distance_h);
	}
	if (phi < M_PI / 2 || phi > 3 * M_PI / 2)
		data_draw.side = 'r';//0xFF8C00;
	else
		data_draw.side = 'l';//0x9ACD32;
	data_draw.length = distance_v;
	data_draw.offset = vertical.offset;
	return (data_draw);
}

t_data_draw			get_length(t_vars *vars, t_data_angle *angle, char (*map)[10], t_sprite **sprite)
{
	t_data_draw		data_draw;
	t_collis		collis;
	t_collis		horisont;
	t_collis		vertical;
	double			phi;

	phi = angle->new_phi;
	if (phi == 0 || phi == M_PI / 2 || phi == M_PI || phi == 3 * M_PI / 2)
	{
		collis = find_block_unique(phi, vars, map, sprite);
		data_draw = get_distance_unique(collis, vars->player, phi);
	}
	else
	{
		horisont = find_block_horisontal(vars, map, phi, sprite);
		vertical = find_block_vertical(vars, map, phi, sprite);
		data_draw = compare_distance(horisont, vertical, vars->player, phi, vars->player.pov * M_PI / 180);
	}
	angle->arr_length[angle->count] = data_draw.length;
	return (data_draw);
}
