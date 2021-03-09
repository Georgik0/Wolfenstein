/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:50:44 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 16:51:11 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	change_coord_a_1(t_vars *vars, int delta_x, int delta_y)
{
	if (vars->map[(vars->player.y + delta_y) / 64]
	[(vars->player.x) / 64] != '1')
	{
		vars->player.y += delta_y;
		return ;
	}
	if (vars->map[(vars->player.y) / 64]
	[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		return ;
	}
}

void	change_coord_a(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = -(int)nearbyint(cos((vars->player.pov - 90) * M_PI / 180) * 3);
	delta_y = (int)nearbyint(sin((vars->player.pov - 90) * M_PI / 180) * 3);
	if (vars->map[(vars->player.y + delta_y) / 64]
	[vars->player.x / 64] == '1' &&
	vars->map[vars->player.y / 64]
	[(vars->player.x + delta_x) / 64] == '1')
		return ;
	if (vars->map[(vars->player.y + delta_y) / 64]
	[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
	change_coord_a_1(vars, delta_x, delta_y);
}

void	change_coord_d_1(t_vars *vars, int delta_x, int delta_y)
{
	if (vars->map[(vars->player.y + delta_y) / 64]
	[(vars->player.x) / 64] != '1')
	{
		vars->player.y += delta_y;
		return ;
	}
	if (vars->map[(vars->player.y) / 64]
	[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		return ;
	}
}

void	change_coord_d(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = (int)nearbyint(cos((vars->player.pov - 90) * M_PI / 180) * 3);
	delta_y = -(int)nearbyint(sin((vars->player.pov - 90) * M_PI / 180) * 3);
	if (vars->map[(vars->player.y + delta_y) / 64]
	[vars->player.x / 64] == '1' &&
	vars->map[vars->player.y / 64]
	[(vars->player.x + delta_x) / 64] == '1')
		return ;
	if (vars->map[(vars->player.y + delta_y) / 64]
	[(vars->player.x + delta_x) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
		return ;
	}
	change_coord_d_1(vars, delta_x, delta_y);
}
