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

static double		get_distance(int x0, int x1, double phi)
{
	double	distance;

	distance = (x0 - x1) / cos(phi);
	if (distance <= 0)
		return (-distance);
	return (distance);
}

static double		compare_distance(t_collis horisont, t_collis vertical, t_player player, double phi)
{
	double	distance_h;
	double	distance_v;

	distance_h = get_distance(player.x, horisont.x, phi);
	distance_v = get_distance(player.x, vertical.x, phi);
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
		length = (int)nearbyint(get_distance(player.x, collis.x, phi));
	}
	else
	{
		horisont = find_block_horisontal(player, map, phi);
		vertical = find_block_vertical(player, map, phi);
		length = (int)nearbyint(compare_distance(horisont, vertical, player, phi));
	}
	return (length);
}

void	draw_3d(int pov, t_player player, char (*map)[10], t_data *img)
{
	int			length;
	float		phi;
	float		new_phi;
	float		d_phi;

	phi = pov + 33;
	d_phi = 66.0 / 1920.0;
	while (phi > pov - 33)
	{
		if (phi < 0)
			new_phi = phi + 360;
		else if (phi > 360)
			new_phi = phi - 360;
		else
			new_phi = phi;


		length = get_length(new_phi * M_PI / 180, player, map);

		phi -= d_phi;
	}
}
