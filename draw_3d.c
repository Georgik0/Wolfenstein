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

void	draw_vertical_line(int x_count, int length, t_data *data)
{
	int		y;
	int		h;

	h = (int)nearbyint(data->d * 64 / length);
	// printf("h = %d\n", h);
	y = 0;
	if (x_count < data->width)
	{
		// printf("x_count = %d    y = %d\n", x_count, y);
		// printf("data->height / 2 - h / 2  =  %d\n", data->height / 2 - h / 2);
		while (y < data->height / 2 - h / 2)
		{
			my_mlx_pixel_put(data, x_count, y, 0x20B2AA);
			// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
				// printf("x = %d   y = %d\n", x_count, y);
			y++;
		}
		// printf("data->height / 2 - h / 2 + h = %d\n", data->height / 2 - h / 2 + h);
		// while (y < data->height / 2 - h / 2 + h && y <= data->height)
		// {
		// 	my_mlx_pixel_put(data, x_count, y, 0xE9967A);
		// 	// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
		// 		// printf("x = %d   y = %d\n", x_count, y);
		// 	y++;
		// }
		// while (y < data->height)
		// {
		// 	my_mlx_pixel_put(data, x_count, y, 0xD3D3D3);
		// 	// if (x_count < 0 || x_count > data->width || y < 0 || y > data->height)
		// 		// printf("x = %d   y = %d\n", x_count, y);
		// 	y++;
		// }
	}
}

void	draw_3d(int pov, t_player player, char (*map)[10], t_data *data)
{
	int			length;
	double		phi;
	double		new_phi;
	double		d_phi;
	int			count;

	phi = pov + 33;
	// phi = pov;
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
			length = get_length(new_phi * M_PI / 180, player, map);
			draw_vertical_line(count, length, data);
		// }
		phi -= d_phi;
		count++;
	}
}
