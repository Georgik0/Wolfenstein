/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:19:50 by skitsch           #+#    #+#             */
/*   Updated: 2021/02/03 17:19:52 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

// int			add_sprite2(t_sprite **sprite_start, double length, double x, double y)
// {
// 	t_sprite	*new;

// 	while (!((*sprite_start)->x == x && (*sprite_start)->y == y) && (*sprite_start)->next != NULL)
// 	{

// 	}
// 	if ((*sprite_start)->x == x && (*sprite_start)->y == y)
// 		return (1);
// 	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
// 		return (0);
// 	new->length = length;
// 	new->x = x;
// 	new->y = y;
// 	if ((*sprite_start)->length < length)
// 	{
// 		new->next = *sprite_start;
// 		*sprite_start = new;
// 		return (1);
// 	}
// 	else if ((*sprite_start)->next == NULL)
// 		new->next = NULL;
// 	else if ((*sprite_start)->next->length > length)
// 		new->next = (*sprite_start)->next;
// 	(*sprite_start)->next = new;
// 	return (1);
// }

int			add_sprite1(t_sprite **sprite_start, double length, double x, double y)
{
	t_sprite	*new;
	t_sprite	*iter;

	// if (x == 96 && y == 160)
	// 	printf("test1\n");
	// if (x == 160 && y == 96)
	// 	printf("test\n");
	// if (x == 160 && y == 160)
	// 	printf("test\n");
	// if (x == 224 && y == 160)
	// 	printf("test\n");
	// if (x == 224 && y == 96)
	// 	printf("test\n");
	iter = *sprite_start;
	if ((iter)->x == x && (iter)->y == y)
		return (1);
	if ((*sprite_start)->length > length)
	{
		while (iter->next != NULL && (iter)->next->length > length)
		{
			if ((iter)->x == x && (iter)->y == y)
				return (1);
			iter = (iter)->next;
		}
	}
	if ((iter)->x == x && (iter)->y == y)
		return (1);
	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return (0);
	new->length = length;
	new->x = x;
	new->y = y;
	if ((*sprite_start)->length <= length)
	{
		new->next = *sprite_start;
		*sprite_start = new;
		return (1);
	}
	else if ((iter)->next == NULL)
		new->next = NULL;
	else if ((iter)->next->length <= length)
	{
		if ((iter)->next->x == x && (iter)->next->y == y)
		{
			free(new);
			return (1);
		}
		new->next = (iter)->next;
	}
	iter->next = new;
	return (1);
}

int			add_sprite(t_sprite **sprite_start, double x, double y, t_player player)
{
	double		length;
	int			out;

	length = sqrt((player.x - x) * (player.x - x) + (player.y - y) * (player.y - y));
	// if (length <= 32)
	// 	return (1);
	if (*sprite_start == NULL)
	{
		if (!(*sprite_start = (t_sprite *)malloc(sizeof(t_sprite))))
			return(0);
		(*sprite_start)->next = NULL;
		(*sprite_start)->length = length;
		(*sprite_start)->x = x;
		(*sprite_start)->y = y;
	}
	else
	{
		if (add_sprite1(sprite_start, length, x, y) == 0)
			return (0);
	}
	return (1);
}

void		clear_sprite(t_sprite **sprite_start)
{
	t_sprite *begin;
	t_sprite *next_list;

	if (!sprite_start || !(*sprite_start))
		return ;
	begin = *sprite_start;
	while (begin)
	{
		next_list = begin->next;
		free(begin);
		begin = next_list;
	}
	*sprite_start = NULL;
}

void		get_sprite_ray(t_player player, double sprite_x, double sprite_y, double d_phi, t_sprite *sprite, int width_sprite, t_data *data, t_data **data_array)
{
	t_sprite_calculation	calc;
	int						color;
	double					y;
	double					x_xmp;

	calc.dx = sprite_x - player.x;
	calc.dy = player.y - sprite_y;
	calc.distance = sprite->length; //sqrt(calc.dx * calc.dx + calc.dy * calc.dy);
	calc.theta = atan2(calc.dy, calc.dx); // радианы

	if (calc.theta < 0)
		calc.theta += 2 * M_PI;
	calc.theta = calc.theta * 180 / M_PI; // перевели calc.theta в градусы
	calc.length = calc.distance * fabs(cos((player.pov - calc.theta) * M_PI / 180));

	calc.h = (int)floor(data_array[0]->d * 64.0 / calc.length);
	calc.step_y = 64.0 / calc.h; //width_sprite / calc.h;
	// if (calc.h > data_array[0]->height)
	// 	calc.step_x = 64.0 / data_array[0]->height;
	// else
		calc.step_x = 64.0 / calc.h;//calc.step_y;
	calc.gamma = player.pov - calc.theta; //если gamma > 0, значит спрайт правее

	// if (calc.dx > 0 && player.pov >= M_PI && player.pov <= 2 * M_PI || calc.dx < 0 && calc.dy < 0)
	// 	calc.gamma += 2 * M_PI;

	if (player.pov >= 0 && player.pov < 33)
	{
		if (calc.theta >= 327)
		{
			calc.gamma = player.pov + (360 - calc.theta);
		}
		else
		{
			calc.gamma = player.pov - calc.theta;
		}

	}
	else if (player.pov >= 327 && player.pov < 360)
	{
		if (calc.theta <= 33)
		{
			calc.gamma = -(360 - player.pov + calc.theta);
		}
		else
		{
			calc.gamma = player.pov - calc.theta;
		}
	}
	else
	{
		calc.gamma = player.pov - calc.theta;
	}


// неправильно считает calc.delta_rays  !!!!!!!!!!!!!!!!
	// calc.gamma и d_phi в градусах
	calc.delta_rays = (int)(calc.gamma / d_phi); // столько лучей между pov и углом, указывающем на середину спрайта
	calc.ray_pov = data_array[0]->width / 2; // луч, идущий по середине экрана (угол направления взгляда игрока)
	calc.middle_sprite = calc.ray_pov + calc.delta_rays; // номер луча, который попал в середину спрайта
	x_xmp = 64.0 / 2.0; //x - координата середины спрайта
	// calc.x0_sprite = calc.middle_sprite - calc.h / 2 * calc.step_y; // первый луч спрайта (может оказаться за границей экрана)

	// нарисуем левую часть спрайта
	int x = calc.middle_sprite;
	double y_xmp;

	while (x >= 0 && x_xmp >= 0)
	{
		if (calc.h > data_array[0]->height)
			y_xmp = (calc.h - data_array[0]->height) / 2;
		else
			y_xmp = 0;
		y = (data_array[0]->height - calc.h) / 2; // с какой высоты начинать рисовать спрайт
		if (y < 0)
			y = 0;
		while (y < data_array[0]->height && y < (calc.h + data_array[0]->height) / 2)
		{
			if (x >= data_array[0]->width)
				break ;
			if (x_xmp < 64)
			{
				color = get_color_sprite(*data_array[1], (int)floor(y_xmp * calc.step_y), (int)floor(x_xmp));
				my_mlx_pixel_put(data_array[0], x, y, color);
			}
			y_xmp++;
			y++;
		}
		x_xmp -= calc.step_x;
		x--;
	}


	// printf("calc.x0_sprite = %f     calc.delta_rays = %d\n", calc.x0_sprite, calc.delta_rays);
// Рисуем спрайт
	// x_xmp = 0;
	// y = data_array[0]->height / 2 - calc.h / 2; // с какой высоты начинать рисовать спрайт
	// if (calc.h > data_array[0]->height)
	// 	calc.y0_sprite = (calc.h - data_array[0]->height) / 2;
	// else
	// 	calc.y0_sprite = 0;
	// while (calc.x0_sprite < 1920 && x_xmp < width_sprite)
	// {
	// 	while (y < data_array[0]->height && calc.y0_sprite < data_array[0]->height)
	// 	{
	// 		// printf("calc.x0_sprite = %f\n", calc.x0_sprite);
	// 		if (calc.x0_sprite >= 0)
	// 		{
	// 			color = get_color_sprite(*data_array[1], y, x_xmp);
	// 			// printf("color = %d\n", color);
	// 			my_mlx_pixel_put(data_array[0], calc.x0_sprite, calc.y0_sprite, color);
	// 		}
	// 		y += calc.step_y;
	// 		calc.y0_sprite++;
	// 	}
	// 	x_xmp += calc.step_y;
	// 	calc.x0_sprite++;
	// }


}
