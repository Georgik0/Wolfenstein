/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:22:46 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 17:22:51 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		press_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keyboard.W = 1;
	if (keycode == 1)
		vars->keyboard.S = 1;
	if (keycode == 0)
		vars->keyboard.A = 1;
	if (keycode == 2)
		vars->keyboard.D = 1;
	if (keycode == 123)
		vars->keyboard.left = 1;
	if (keycode == 124)
		vars->keyboard.right = 1;
	if (keycode == 53)
	{
		make_free_vars(vars);
		exit(0);
	}
	return (0);
}

int		dismiss_keyboard(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keyboard.W = 0;
	if (keycode == 1)
		vars->keyboard.S = 0;
	if (keycode == 0)
		vars->keyboard.A = 0;
	if (keycode == 2)
		vars->keyboard.D = 0;
	if (keycode == 123)
		vars->keyboard.left = 0;
	if (keycode == 124)
		vars->keyboard.right = 0;
	return (0);
}
