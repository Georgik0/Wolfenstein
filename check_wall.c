/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:30:01 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/08 18:30:03 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		check_up(char **map, int x, int y)
{
	if (y == 0)
		return (-1);
	while (y-- > 0)
	{
		if (x > ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_bottom(char **map, int x, int y, int length_map_y)
{
	if (y == length_map_y - 1)
		return (-1);
	while (y++ < length_map_y - 1)
	{
		if (x > ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_left(char **map, int x, int y)
{
	if (x == 0)
		return (-1);
	while (x-- > 0)
	{
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_right(char **map, int x, int y)
{
	if (x == ft_strlen(map[y]) - 1)
		return (-1);
	while (x-- > 0)
	{
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}
