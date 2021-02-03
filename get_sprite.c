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

t_sprite	*add_sprite(t_sprite *sprite)
{
	t_sprite	*new;
	t_sprite	*prev;
	while (sprite->next != NULL)
	{
		sprite = sprite->next;
	}
	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return (NULL);
	new->next = NULL;
	sprite->next = new;

}

t_sprite	*get_sprite(t_sprite *sprite, double x, double y)
{
	if (sprite == NULL)
	{
		if (!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
			return(NULL);
		sprite->next = NULL;
		sprite->prev = NULL;
	}
	else
	{

	}
}
