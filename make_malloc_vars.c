/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_malloc_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:18:47 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/03 12:19:00 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	set_flags(t_vars *vars)
{
	vars->flags.c = 0;
	vars->flags.ea = 0;
	vars->flags.f = 0;
	vars->flags.no = 0;
	vars->flags.r = 0;
	vars->flags.s = 0;
	vars->flags.so = 0;
	vars->flags.we = 0;
	vars->flags.summ = 0;
	vars->flags.map_start = 0;
	vars->flags.map_end = 0;
	vars->player.check = 0;
	vars->keyboard.a = 0;
	vars->keyboard.d = 0;
	vars->keyboard.s = 0;
	vars->keyboard.w = 0;
	vars->keyboard.left = 0;
	vars->keyboard.right = 0;
}

void	set_file_name(t_vars *vars)
{
	vars->map_lst = NULL;
	vars->dir_wall_down = NULL;
	vars->dir_wall_left = NULL;
	vars->dir_wall_right = NULL;
	vars->dir_wall_up = NULL;
	vars->dir_sprite = NULL;
	vars->map = NULL;
}

int		make_malloc_vars(t_vars *vars)
{
	int	i;

	i = 0;
	if (!(vars->data_array = (t_data **)malloc(6 * sizeof(t_data *))))
	{
		return (-5);
	}
	while (i < 6)
	{
		if (!(vars->data_array[i++] = (t_data *)malloc(sizeof(t_data))))
		{
			while (--i >= 0)
				free(vars->data_array[i]);
			free(vars->data_array);
			return (-5);
		}
	}
	set_file_name(vars);
	set_flags(vars);
	get_width_height(vars);
	return (1);
}
