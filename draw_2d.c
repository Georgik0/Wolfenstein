/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:04:37 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 17:04:40 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	calculate_draw_line(t_coord_line coord, t_draw_line *dr_line)
{
	dr_line->dy = coord.y1 - coord.y0;
	dr_line->dx = coord.x1 - coord.x0;
	dr_line->delta_x = ft_abs(dr_line->dx);
	dr_line->delta_y = ft_abs(dr_line->dy);
	dr_line->dx = dr_line->dx > 0 ? 1 : -1;
	dr_line->dy = dr_line->dy > 0 ? 1 : -1;
	dr_line->er = dr_line->delta_x - dr_line->delta_y;
	dr_line->er2 = 1;
}

void	print_line(t_coord_line coord, t_data *img)
{
	t_draw_line	dr_line;

	calculate_draw_line(coord, &dr_line);
	my_mlx_pixel_put(img, coord.x1, coord.y1, 0xFFFFFF);
	while (coord.x0 != coord.x1 || coord.y0 != coord.y1)
	{
		my_mlx_pixel_put(img, coord.x0, coord.y0, 0xFFFFFF);
		dr_line.er2 = dr_line.er * 2;
		if (dr_line.er2 > -dr_line.delta_y)
		{
			dr_line.er -= dr_line.delta_y;
			coord.x0 += dr_line.dx;
		}
		if (dr_line.er2 < dr_line.delta_x)
		{
			dr_line.er += dr_line.delta_x;
			coord.y0 += dr_line.dy;
		}
	}
}
