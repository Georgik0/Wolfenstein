/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:06:26 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/03 21:06:28 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_length_x(t_my_map *map_lst)
{
	int		number;

	number = 0;
	while (map_lst)
	{
		map_lst = map_lst->next;
		number++;
	}
	return (number);
}

int		get_map(t_vars *vars)
{
	int		number_x;

	number_x = get_length_x(vars->map_lst);
}
