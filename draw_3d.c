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

// void	draw_vertical_line(int x_count, double length, t_data *data, double phi)
void	draw_vertical_line(int x_count, t_data_draw data_draw, t_data *data, double phi)
{
	int			y;
	int			h;
	double		length;

	length = data_draw.length;
	if (length == 0)
		h = INFINITY;
	else
		h = (int)floor(data->d * 64 / length);
	y = 0;
	if (x_count < data->width)
	{
		// printf("x_count = %d    y = %d\n", x_count, y);
		// printf("data->height / 2 - h / 2  =  %d\n", data->height / 2 - h / 2);
		while (y < data->height / 2 - h / 2)
		{
			// my_mlx_pixel_put(data, x_count, y, data_draw.color);
			my_mlx_pixel_put(data, x_count, y, 0x00CED1);
			// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
				// printf("x = %d   y = %d\n", x_count, y);
			y++;
		}
		// printf("data->height / 2 - h / 2 + h = %d\n", data->height / 2 - h / 2 + h);
		while (y <= data->height / 2 - h / 2 + h && y <= data->height)
		{
			// my_mlx_pixel_put(data, x_count, y, data_draw.color);
			my_mlx_pixel_put(data, x_count, y, data_draw.color);
			// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
				// printf("x = %d   y = %d\n", x_count, y);
			y++;
		}
		while (y < data->height)
		{
			// my_mlx_pixel_put(data, x_count, y, data_draw.color);
			my_mlx_pixel_put(data, x_count, y, 0xF5F5F5);
			// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
				// printf("x = %d   y = %d\n", x_count, y);
			y++;
		}
	}
}

void	draw_3d(int pov, t_player player, char (*map)[10], t_data *data)
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
			// length = get_length(pov, new_phi * M_PI / 180, player, map);
			draw_vertical_line(count, data_draw, data, new_phi * M_PI / 180);
			// draw_vertical_line(count, length, data, new_phi * M_PI / 180);
		// }
		phi -= d_phi;
		count++;
	}
}
