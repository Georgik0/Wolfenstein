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
	dst = data.addr + (y_xmp * data.line_length + x_xmp * (data.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

unsigned int		get_color_sprite(t_data data, int y, int x)
{
	int		color;
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}
