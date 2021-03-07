/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:20:57 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 18:20:59 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	draw_sky(int *y, t_data_draw data_draw, t_vars *vars)
{
	while (*y < vars->data_array[0]->height / 2 - data_draw.h / 2)
	{
		my_mlx_pixel_put(vars->data_array[0], data_draw.x_count, *y, vars->color_ceilling);
		(*y)++;
	}
}

void	draw_wall(int *y, t_data_draw data_draw, t_data **data_array)
{
	int	y_xmp;

	if (data_draw.h > data_array[0]->height)
		y_xmp = (data_draw.h - data_array[0]->height) / 2;
	else
		y_xmp = 0;
	while (*y < data_array[0]->height / 2 + data_draw.h / 2 && *y < data_array[0]->height)
	{
		if (data_draw.side == 'l')
			data_draw.color = get_color(*data_array[1], y_xmp, data_draw.offset, data_draw.h);
		else if (data_draw.side == 'u')
			data_draw.color = get_color(*data_array[2], y_xmp, data_draw.offset, data_draw.h);
		else if (data_draw.side == 'd')
			data_draw.color = get_color(*data_array[3], y_xmp, data_draw.offset, data_draw.h);
		else
			data_draw.color = get_color(*data_array[4], y_xmp, data_draw.offset, data_draw.h);
		my_mlx_pixel_put(data_array[0], data_draw.x_count, *y, data_draw.color);
		(*y)++;
		y_xmp++;
	}
}

void	draw_ground(int *y, t_data_draw data_draw, t_vars *vars)
{
	while (*y < vars->data_array[0]->height)
	{
		my_mlx_pixel_put(vars->data_array[0], data_draw.x_count, *y, vars->color_floor);
		(*y)++;
	}
}

void	draw_vertical_line(t_data_draw data_draw, t_vars *vars)
{
	int			y;
	int			y_xmp;

	data_draw.h = (int)floor(vars->data_array[0]->d * 64 / data_draw.length);
	y = 0;
	if (data_draw.x_count < vars->data_array[0]->width)
	{
		draw_sky(&y, data_draw, vars);
		draw_wall(&y, data_draw, vars->data_array);
		draw_ground(&y, data_draw, vars);
	}
}
