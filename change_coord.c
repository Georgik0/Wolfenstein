/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:47:33 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 16:47:35 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	change_coord_w_1(t_vars *vars, int delta_x, int delta_y)
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

void	change_coord_w(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = (int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
	delta_y = -(int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
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
	change_coord_w_1(vars, delta_x, delta_y);
}

void	change_coord_s_1(t_vars *vars, int delta_x, int delta_y)
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

void	change_coord_s(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
	delta_y = (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
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
	change_coord_s_1(vars, delta_x, delta_y);
}

int		change_coord(t_vars *vars)
{
	if (vars->keyboard.left)
		vars->player.pov += 2;
	if (vars->keyboard.right)
		vars->player.pov -= 2;
	if (vars->player.pov >= 360)
		vars->player.pov -= 360;
	if (vars->player.pov < 0)
		vars->player.pov += 360;
	if (vars->keyboard.W)
		change_coord_w(vars);
	if (vars->keyboard.S)
		change_coord_s(vars);
	if (vars->keyboard.A)
		change_coord_a(vars);
	if (vars->keyboard.D)
		change_coord_d(vars);
	return (0);
}
