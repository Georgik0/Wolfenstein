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

int		get_data_angle(t_data_angle *angle, int pov, int width)
{
	angle->phi = pov + 33;
	angle->d_phi = 66.0 / width;
	angle->count = 0;
	if (!(angle->arr_length = (int *)malloc((width + 1) * sizeof(int))))
	{
		angle->arr_length = NULL;
		return (-1);
	}
	return (0);
}

void	correct_angle(t_data_angle *angle)
{
	if (angle->phi < 0)
		angle->new_phi = (angle->phi + 360) * M_PI / 180;
	else if (angle->phi > 360)
		angle->new_phi = (angle->phi - 360) * M_PI / 180;
	else
		angle->new_phi = angle->phi * M_PI / 180;
}

int		draw_3d(t_vars *vars)
{
	t_data_draw		data_draw;
	t_data_angle	angle;
	t_sprite		*sprite;
	int				count;

	sprite = NULL;
	if (get_data_angle(&angle, vars->player.pov,
	vars->data_array[0]->width) == -1)
		return (-1);
	data_draw.x_count = 0;
	while (data_draw.x_count < vars->data_array[0]->width)
	{
		correct_angle(&angle);
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
	return (1);
}
