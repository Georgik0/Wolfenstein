/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:59:18 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/25 19:59:20 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"
#include "mlx/mlx.h"

void	draw_vertical_line(int x_count, t_data_draw data_draw, t_data *data, double phi, t_data **data_array)
{
	int			y;
	int			y_xmp;
	int			h;
	double		length;
	int			color;

	length = data_draw.length;
	if (length == 0)
		h = INFINITY;
	else
		h = (int)floor(data_array[0]->d * 64 / length);
	y = 0;
	if (x_count < data_array[0]->width)
	{
		while (y < data_array[0]->height / 2 - h / 2)
		{
			my_mlx_pixel_put(data_array[0], x_count, y, 0x00CED1);
			y++;
		}
		if (h > data_array[0]->height)
			y_xmp = (h - data_array[0]->height) / 2;
		else
			y_xmp = 0;
		while (y < data_array[0]->height / 2 + h / 2 && y <= data_array[0]->height)
		{
			if (data_draw.side == 'l')
				color = get_color(*data_array[1], y_xmp, data_draw.offset, h);
			else if (data_draw.side == 'u')
				color = get_color(*data_array[2], y_xmp, data_draw.offset, h);
			else if (data_draw.side == 'd')
				color = get_color(*data_array[3], y_xmp, data_draw.offset, h);
			else
				color = get_color(*data_array[4], y_xmp, data_draw.offset, h);
			my_mlx_pixel_put(data_array[0], x_count, y, color);
			y++;
			y_xmp++;
		}
		while (y < data_array[0]->height)
		{
			my_mlx_pixel_put(data_array[0], x_count, y, 0x808080);
			y++;
		}
	}
}

void	draw_3d(int pov, t_player player, char (*map)[10], t_data *data, t_data **data_array)
{
	t_data_draw	data_draw;
	double		length;
	double		phi;
	double		new_phi;
	double		d_phi;
	int			count;

	phi = pov + 33;
	d_phi = 66.0 / 1920.0;
	count = 0;
	// count = 960;
	while (count < 1920)
	{
		// if (count >= 890 && count <= 920)
		// {
			if (phi < 0)
				new_phi = phi + 360;
			else if (phi > 360)
				new_phi = phi - 360;
			else
				new_phi = phi;
			data_draw = get_length(pov, new_phi * M_PI / 180, player, map);
			draw_vertical_line(count, data_draw, data, new_phi * M_PI / 180, data_array);
			// draw_vertical_line(count, length, data, new_phi * M_PI / 180);
		// }
		phi -= d_phi;
		count++;
	}
}
