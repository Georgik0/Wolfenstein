/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:35:01 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/01 17:35:04 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

unsigned int		get_color(t_data data, int y, double offset, int h)
{
	double	scale_y;
	int		y_xmp;
	int		x_xmp;
	int		color;
	char	*dst;

	scale_y = 64.0 / h;
	y_xmp = (int)floor(y * scale_y);
	x_xmp = (int)floor(64.0 * offset);
	// printf("get_color    offset = %f   h = %d   scale_y = %f   y_xmp = %d   x_xmp = %d\n", offset, h, scale_y, y_xmp, x_xmp);
	dst = data.addr + (y_xmp * data.line_length + x_xmp * (data.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

unsigned int		get_color_sprite(t_data data, int y, int x)
{
	// double	scale_y;
	// int		y_xmp;
	// int		x_xmp;
	int		color;
	char	*dst;

	// scale_y = 64.0 / h;
	// y_xmp = (int)floor(y * scale_y);
	// x_xmp = (int)floor(64.0 * offset);
	// printf("get_color    offset = %f   h = %d   scale_y = %f   y_xmp = %d   x_xmp = %d\n", offset, h, scale_y, y_xmp, x_xmp);
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

// void	put_pixel_texture(t_data data, t_vars *vars, int y_screen, int x_img)
// {
// 	int		x_img;
// 	int		y_img;
// 	int		color;
// 	char	*dst;
// 	double	scale;

// 	scale = data.height / vars->data->height;
// 	y_img = y_screen * scale;
// 	dst = data.addr + (y_img * 4 + x_img * 4);
// 	color = (unsigned int)*dst;

// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
