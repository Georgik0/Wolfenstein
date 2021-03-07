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

void	draw_sky(int *y, t_data_draw data_draw, t_vars *vars)
{
	while (*y < vars->data_array[0]->height / 2 - data_draw.h / 2)
	{
		my_mlx_pixel_put(vars->data_array[0], data_draw.x_count, *y, vars->color_ceilling);
		(*y)++;
	}
	if (*y-1 == (int)Y && data_draw.x_count == (int)X)
	{
		printf("addres = %p\n", vars->data_array[0]->addr);
		printf("addr_p = %p\n", vars->data_array[0]->addr + ((*y-1) * vars->data_array[0]->line_length + data_draw.x_count * (vars->data_array[0]->bits_per_pixel / 8)));
		printf("line_length = %d    vars->data_array[0]->bits_per_pixel / 8 = %d\n", vars->data_array[0]->line_length, vars->data_array[0]->bits_per_pixel / 8);
		printf("x = %d  y = %d    color = %x\n", data_draw.x_count, *y-1, vars->color_ceilling);
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
		if (*y == (int)Y && data_draw.x_count == (int)X)
		{
			printf("addres = %p\n", data_array[0]->addr);
			printf("addr_p = %p\n", data_array[0]->addr + (*y * data_array[0]->line_length + data_draw.x_count * (data_array[0]->bits_per_pixel / 8)));
			printf("line_length = %d    vars->data_array[0]->bits_per_pixel / 8 = %d\n", data_array[0]->line_length, data_array[0]->bits_per_pixel / 8);
			printf("x = %d  y = %d    color = %x\n", data_draw.x_count, *y, data_draw.color);
		}
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
	if (*y-1 == (int)Y && data_draw.x_count == (int)X)
	{
		printf("addres = %p\n", vars->data_array[0]->addr);
		printf("addr_p = %p\n", vars->data_array[0]->addr + ((*y-1) * vars->data_array[0]->line_length + data_draw.x_count * (vars->data_array[0]->bits_per_pixel / 8)));
		printf("line_length = %d    vars->data_array[0]->bits_per_pixel / 8 = %d\n", vars->data_array[0]->line_length, vars->data_array[0]->bits_per_pixel / 8);
		printf("x = %d  y = %d    color = %x\n", data_draw.x_count, *y-1, vars->color_floor);
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

int		get_data_angle(t_data_angle *angle, int pov, int width)
{
	angle->phi = pov + 33;
	angle->d_phi = 66.0 / width;
	angle->count = 0;
	if (!(angle->arr_length = (int *)malloc(width * sizeof(int) + 1)))
	{
		angle->arr_length = NULL;
		return (-1);
	}
	return (0);
}

void	draw_3d(t_vars *vars)
{
	t_data_draw		data_draw;
	t_data_angle	angle;
	t_sprite		*sprite;
	int				count;

	sprite = NULL;
	// if (get_data_angle(&angle, pov, data_array[0]->width) == -1)
	// 	return ; // вернуть ошибку
	if (get_data_angle(&angle, vars->player.pov, vars->data_array[0]->width) == -1)
		return ; //  вернуть ошибку
	data_draw.x_count = 0;
	while (data_draw.x_count < vars->data_array[0]->width)
	{
		if (angle.phi < 0)
			angle.new_phi = (angle.phi + 360) * M_PI / 180;
		else if (angle.phi > 360)
			angle.new_phi = (angle.phi - 360) * M_PI / 180;
		else
			angle.new_phi = angle.phi * M_PI / 180;
		data_draw = get_length(vars, &angle, &sprite);
		data_draw.x_count = angle.count;
		draw_vertical_line(data_draw, vars);
		angle.phi -= angle.d_phi;
		(angle.count)++;
	}
	if (sprite != NULL)
		get_sprite_ray(&(vars->player), &angle, sprite, vars->data_array);
	free(angle.arr_length);
	clear_sprite(&sprite);
}
