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

void	put_pixel_texture(t_data data, t_vars *vars, int y_screen, int x_img)
{
	int		x_img;
	int		y_img;
	int		color;
	char	*dst;
	double	scale;

	scale = data.height / vars->data->height;
	y_img = y_screen * scale;
	dst = data.addr + (y_img * 4 + x_img * 4);
	color = (unsigned int)*dst;

}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
