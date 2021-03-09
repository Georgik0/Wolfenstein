/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:13:30 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/08 17:13:32 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			draw_game(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	change_coord(vars);
	if (draw_3d(vars) == -1)
	{
		make_free_vars(vars);
		exit(0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
	vars->data_array[0]->img, 0, 0);
	return (0);
}

int			make_exit(t_vars *vars)
{
	make_free_vars(vars);
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_vars		vars;
	int			out;

	if ((out = parser(argc, argv, &vars)) != 1)
	{
		error_processing(out);
		exit(0);
	}
	mlx_loop_hook(vars.mlx, &draw_game, &vars);
	mlx_hook(vars.win, 2, 0, &press_keyboard, &vars);
	mlx_hook(vars.win, 3, 0, &dismiss_keyboard, &vars);
	mlx_hook(vars.win, 17, 0, &make_exit, &vars);
	mlx_do_sync(vars.mlx);
	mlx_loop(vars.mlx);
	return (0);
}
