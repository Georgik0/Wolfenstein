/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:11:38 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/09 21:11:39 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int			get_around_b_y(double b_y, double phi)
{
	if (phi > M_PI && phi < 3 * M_PI / 2)
	{
		if (b_y - (int)b_y / 64 * 64 >= 63)
			return ((int)b_y / 64);
	}
	if (phi > 3 * M_PI / 2 && phi < 2 * M_PI)
	{
		if (b_y - (int)b_y / 64 * 64 >= 63)
			return ((int)b_y / 64);
	}
	if (phi > 0 && phi < M_PI / 2)
	{
		if (b_y - (int)b_y / 64 * 64 >= 63)
			return ((int)b_y / 64 + 1);
	}
	if (phi > M_PI / 2 && phi < M_PI)
	{
		if (b_y - (int)b_y / 64 * 64 >= 63)
			return ((int)b_y / 64 + 1);
	}
	return (b_y / 64);
}

t_collis	collision_width_vertical(t_coord_vertic vertic, double phi,
t_vars *vars, t_sprite **sp)
{
	t_xy_data	xy;
	t_collis	collis;

	xy.y = get_around_b_y(vertic.by, phi);
	xy.x = (int)nearbyint(vertic.bx) / 64;
	while (xy.y >= 0 && xy.x >= 0 && xy.y < vars->length_map_y && xy.x <
	(int)ft_strlen(vars->map[xy.y]) - 1 && vars->map[xy.y][xy.x] != '1')
	{
		if (vars->map[xy.y][xy.x] == '2')
		{
			if (!add_sprite(sp, xy.x * 64 + 32, xy.y * 64 + 32, vars->player))
			{
				collis.err = 1;
				return (collis);
			}
		}
		vertic.bx += vertic.dx;
		vertic.by += vertic.dy;
		xy.y = get_around_b_y(vertic.by, phi);
		xy.x = (int)(nearbyint(vertic.bx) / 64);
	}
	collis.x = vertic.bx;
	collis.y = vertic.by;
	collis.offset = (vertic.by - (int)(vertic.by / 64) * 64) / 64;
	return (collis);
}

t_collis	find_block_vertical(t_vars *vars, double phi, t_sprite **sprite)
{
	t_coord_vertic	vertic;
	t_collis		collis;

	if (phi > 3.0 * M_PI / 2.0 || phi < M_PI / 2.0)
	{
		vertic.bx = (int)((vars->player.x / 64) * 64) + 64;
		vertic.dx = 64;
	}
	else
	{
		vertic.bx = (int)((vars->player.x / 64) * 64) - 1;
		vertic.dx = -64;
	}
	vertic.by = vars->player.y + (vars->player.x - vertic.bx) * tan(phi);
	if ((phi > 0.0 && phi < M_PI / 2.0) || phi > 3.0 * M_PI / 2.0)
	{
		vertic.dy = -64.0 * tan(phi);
	}
	else
		vertic.dy = 64.0 * tan(phi);
	collis = collision_width_vertical(vertic, phi, vars, sprite);
	return (collis);
}
