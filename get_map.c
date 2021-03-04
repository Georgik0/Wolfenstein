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

int				get_length_x(t_my_map *map_lst)
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

static int		make_malloc_map(t_vars *vars)
{
	int			i;
	t_my_map	*lst;

	if (!(vars->map = (char **)malloc(sizeof(char *) *
	(vars->length_map_y + 1))))
		return (-1);
	vars->map[vars->length_map_y] = NULL;
	i = 0;
	lst = vars->map_lst;
	while (i < vars->length_map_y)
	{
		// printf("%s\n", lst->line);
		vars->map[i] = lst->line;
		lst = lst->next;
		i++;
	}
	return (1);
}

int				get_map(t_vars *vars)
{
	int		number_x;

	vars->length_map_y = get_length_x(vars->map_lst);
	printf("get_map     length_map_y = %d\n", vars->length_map_y);
	if (make_malloc_map(vars) == -1)
		return (-1);
	return (1);
}
