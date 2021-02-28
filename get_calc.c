/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:39:36 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/27 16:39:38 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	get_calc1(t_sprite *sprite, t_sprite_calculation *calc, t_player *player, t_data **data_array)
{
	calc->dx = sprite->x - player->x;
	calc->dy = player->y - sprite->y;
	calc->distance = sprite->length; //sqrt(calc.dx * calc.dx + calc.dy * calc.dy);
	calc->theta = atan2(calc->dy, calc->dx); // радианы
	if (calc->theta < 0)
		calc->theta += 2 * M_PI;
	calc->theta = calc->theta * 180 / M_PI; // перевели calc.theta в градусы
	calc->length = calc->distance * fabs(cos((player->pov - calc->theta) * M_PI / 180));
	calc->real_h = (int)floor(data_array[0]->d * 64.0 / calc->length); // высота блока, в котором стоит спрайт
	calc->h = (int)floor(data_array[0]->d * calc->sp_heigh / calc->length); // высота спрайта
	calc->step_y = (double)data_array[5]->height / (double)calc->h;
	// printf("calc->step_y = %f    data_array[5]->height = %d     calc->h = %d\n", calc->step_y, data_array[5]->height, calc->h);
	calc->gamma = player->pov - calc->theta; //если gamma > 0, значит спрайт правее
}

void	get_calc2(t_sprite *sprite, t_sprite_calculation *calc, t_player *player, t_data **data_array)
{
	double	d_gamma;

	d_gamma = acos((calc->distance - calc->sp_width * cos((90 - calc->gamma) * M_PI / 180)) / sqrt(calc->sp_width * calc->sp_width + calc->distance * calc->distance - 2 * calc->sp_width * calc->distance * cos((90 - calc->gamma) * M_PI / 180))) * 180 / M_PI; // в градусах
	calc->step_x = data_array[5]->width / 2 / (d_gamma / calc->d_phi); // 32(половина размера спрайта) делим на кол-во лучей, приходящихся на данный спрайт
	if (player->pov >= 0 && player->pov < 33)
	{
		if (calc->theta >= 327)
			calc->gamma = player->pov + (360 - calc->theta);
		else
			calc->gamma = player->pov - calc->theta;
	}
	else if (player->pov >= 327 && player->pov < 360)
	{
		if (calc->theta <= 33)
			calc->gamma = -(360 - player->pov + calc->theta);
		else
			calc->gamma = player->pov - calc->theta;
	}
	else
		calc->gamma = player->pov - calc->theta;
	calc->delta_rays = (int)(calc->gamma / calc->d_phi); // столько лучей между pov и углом, указывающем на середину спрайта
	calc->ray_pov = data_array[0]->width / 2; // луч, идущий по середине экрана (угол направления взгляда игрока)
	calc->middle_sprite = calc->ray_pov + calc->delta_rays; // номер луча, который попал в середину спрайта
}

void	get_calc(t_sprite *sprite, t_sprite_calculation *calc, t_player *player, t_data **data_array)
{
	get_calc1(sprite, calc, player, data_array);
	get_calc2(sprite, calc, player, data_array);
}
