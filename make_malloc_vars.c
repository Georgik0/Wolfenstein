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
	vars->flags.C = 0;
	vars->flags.EA = 0;
	vars->flags.F = 0;
	vars->flags.NO = 0;
	vars->flags.R = 0;
	vars->flags.S = 0;
	vars->flags.SO = 0;
	vars->flags.WE = 0;
	vars->flags.summ = 0;
	vars->flags.map_start = 0;
	vars->flags.map_end = 0;
	vars->player.check = 0;
	vars->keyboard.A = 0;
	vars->keyboard.D = 0;
	vars->keyboard.S = 0;
	vars->keyboard.W = 0;
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
	return (1);
}
