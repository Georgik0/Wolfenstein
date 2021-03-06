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

#include "mlx/mlx.h"
#include "header/my_type.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_map(int map_len_x, int map_len_y, int size_cub, char (*map)[10], t_data *img)
{
	int		i = 0;
	int		j = 0;
	int		max_X = map_len_x * size_cub;
	int		max_Y = map_len_y * size_cub;

	while (i < max_Y)
	{
		j = 0;
		while (j < max_X)
		{
			if (map[j / size_cub][i / size_cub] == '1')
				my_mlx_pixel_put(img, i, j, 0xFF6347);
			else
				my_mlx_pixel_put(img, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

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

void	change_coord_W(t_vars *vars)
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

void	change_coord_S(t_vars *vars)
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

void	change_coord_A(t_vars *vars)
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

void	change_coord_D(t_vars *vars)
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
		change_coord_W(vars);
	if (vars->keyboard.S)
		change_coord_S(vars);
	if (vars->keyboard.A)
		change_coord_A(vars);
	if (vars->keyboard.D)
		change_coord_D(vars);
	return (0);
}

void	print_line(int x0, int y0, int x1, int y1, t_data *img)
{
	int	delta_x;
	int	delta_y;
	int	er;
	int	er2;
	int	dy;
	int	dx;

	dy = y1 - y0;
	dx = x1 - x0;
	delta_x = ft_abs(dx);
	delta_y = ft_abs(dy);
	dx = dx > 0 ? 1 : -1;
	dy = dy > 0 ? 1 : -1;
	er = delta_x - delta_y;
	er2 = 1;
	my_mlx_pixel_put(img, x1, y1, 0xFFFFFF);
	while (x0 != x1 || y0 != y1)
	{
		my_mlx_pixel_put(img, x0, y0, 0xFFFFFF);
		er2 = er * 2;
		if (er2 > -delta_y)
		{
			er -= delta_y;
			x0 += dx;
		}
		if (er2 < delta_x)
		{
			er += delta_x;
			y0 += dy;
		}
	}
}

void	print_player(int playerX, int playerY, char map[][10], t_data *img)
{
	my_mlx_pixel_put(img, playerX, playerY, 0x7CFC00);
}

int		draw_game(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	change_coord(vars);
	// print_map(vars->data_map.map_len_x, vars->data_map.map_len_y, vars->data_map.size_cub, vars->data_map.map, vars->data);
	// draw_ray(vars->player.pov, vars->player, vars->data_map.map, vars->data);
	draw_3d(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data_array[0]->img, 0, 0);
	// mlx_do_sync(vars->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	int			img_width;
	int			img_heigh;

	if (parser(argc, argv, &vars) == -1)
	{
		printf("Error\n");
		exit(0);
	}
	mlx_loop_hook(vars.mlx, &draw_game, &vars);
	mlx_hook(vars.win, 2, 0, &press_keyboard, &vars);
	mlx_hook(vars.win, 3, 0, &dismiss_keyboard, &vars);
	mlx_do_sync(vars.mlx);
	mlx_loop(vars.mlx);
	return (0);
}
