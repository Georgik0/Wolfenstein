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

int			add_sprite1(t_sprite **sprite_start, double length, double x, double y)
{
	t_sprite	*new;

	while ((*sprite_start)->length <= length && (*sprite_start)->next != NULL && (*sprite_start)->next->length <= length)
	{
		if ((*sprite_start)->x == x && (*sprite_start)->y == y)
			return (1);
		*sprite_start = (*sprite_start)->next;
	}
	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return (0);
	new->length = length;
	new->x = x;
	new->y = y;
	if ((*sprite_start)->length > length)
	{
		new->next = *sprite_start;
		*sprite_start = new;
		return (1);
	}
	else if ((*sprite_start)->next == NULL)
		new->next = NULL;
	else if ((*sprite_start)->next->length > length)
		new->next = (*sprite_start)->next;
	(*sprite_start)->next = new;
	return (1);
}

int			add_sprite(t_sprite **sprite_start, double x, double y, t_player player)
{
	double		length;
	int			out;

	length = sqrt((player.x - x) * (player.x - x) + (player.y - y) * (player.y - y));
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

// void		srite_coord(t_player player, double sprite_x, double sprite_y, double d_phi)
// {
// 	t_sprite_calculation	calc;

// 	calc.dx = sprite_x - player.x;
// 	calc.dy = sprite_y - player.y;
// 	calc.distance = sqrt(calc.dx * calc.dx + calc.dy * calc.dy);
// 	calc.theta = atan2(calc.dy, calc.dx);
// 	calc.gamma = calc.theta - player.pov * M_PI / 180;
// 	if (calc.dx > 0 && player.pov >= 180 && player.pov <= 360 || calc.dx < 0 && calc.dy < 0)
// 		calc.gamma += 2 * M_PI;
// 	calc.delta_rays = (int)(calc.gamma / d_phi);
// 	calc.ray_center =
// }