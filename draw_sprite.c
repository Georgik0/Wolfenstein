/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:51:45 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/27 14:51:46 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	get_dr_sp(t_draw_sprite	*dr_sp, t_data **data_array, t_sprite_calculation *calc)
{
	if (calc->h > data_array[0]->height)
		dr_sp->y_xmp = (calc->h - data_array[0]->height) / 2 * calc->step_y;
	else
		dr_sp->y_xmp = 0;
	dr_sp->y = (data_array[0]->height - calc->h) / 2; // с какой высоты начинать рисовать спрайт
	if (dr_sp->y < 0)
		dr_sp->y = 0;
}

void	draw_left_part(t_data **data_array, t_sprite_calculation *calc)
{
	t_draw_sprite	dr_sp;

	dr_sp.x = calc->middle_sprite;
	dr_sp.x_xmp = data_array[5]->width / 2;
	while (dr_sp.x >= 0 && dr_sp.x_xmp >= 0)
	{
		get_dr_sp(&dr_sp, data_array, calc);
		while (dr_sp.y < data_array[0]->height && dr_sp.y < (calc->h + data_array[0]->height) / 2)
		{
			if (dr_sp.x >= data_array[0]->width)
				break ;
			if (dr_sp.x_xmp < data_array[5]->width)
			{
				dr_sp.color = get_color_sprite(*data_array[5], (int)floor(dr_sp.y_xmp), (int)floor(dr_sp.x_xmp));
				my_mlx_pixel_put(data_array[0], dr_sp.x, dr_sp.y, dr_sp.color);
			}
			dr_sp.y_xmp += calc->step_y;
			dr_sp.y++;
		}
		dr_sp.x_xmp -= calc->step_x;
		dr_sp.x--;
	}
}

void	draw_right_part(t_data **data_array, t_sprite_calculation *calc)
{
	t_draw_sprite	dr_sp;

	dr_sp.x = calc->middle_sprite;
	dr_sp.x_xmp = data_array[5]->width / 2;
	while (dr_sp.x < data_array[0]->width && dr_sp.x_xmp < data_array[5]->width)
	{
		get_dr_sp(&dr_sp, data_array, calc);
		while (dr_sp.y < data_array[0]->height && dr_sp.y < (calc->h + data_array[0]->height) / 2)
		{
			if (dr_sp.x <= 0)
				break ;
			if (dr_sp.x_xmp >= 0)
			{
				dr_sp.color = get_color_sprite(*data_array[5], (int)floor(dr_sp.y_xmp * calc->step_y), (int)floor(dr_sp.x_xmp));
				my_mlx_pixel_put(data_array[0], dr_sp.x, dr_sp.y, dr_sp.color);
			}
			dr_sp.y_xmp++;
			dr_sp.y++;
		}
		dr_sp.x_xmp += calc->step_x;
		dr_sp.x++;
	}
}

void	draw_sprite(t_sprite_calculation *calc, t_data **data_array)
{
	draw_left_part(data_array, calc);
	draw_right_part(data_array, calc);
}
