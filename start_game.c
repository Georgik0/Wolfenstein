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

int		change_coord(t_vars *vars)
{
	if (vars->keyboard.left)
		vars->player.pov += 1;
	if (vars->keyboard.right)
		vars->player.pov -= 1;
	if (vars->player.pov >= 360)
		vars->player.pov -= 360;
	if (vars->player.pov < 0)
		vars->player.pov += 360;
	if (vars->keyboard.W)
	{
		vars->player.x += (int)nearbyint(cos(vars->player.pov * M_PI / 180) * 1.5);
		// printf("cos = %f\n", cos(vars->player.pov) * 5);
		vars->player.y += -(int)nearbyint(sin(vars->player.pov * M_PI / 180) * 1.5);
	}
	if (vars->keyboard.S)
	{
		vars->player.x += -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 1.5);
		vars->player.y += (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 1.5);
	}
	// if (vars->keyboard.A)
	// 	vars->player.x -= 1;
	// if (vars->keyboard.D)
	// 	vars->player.x += 1;
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
	print_map(vars->data_map.map_len_x, vars->data_map.map_len_y, vars->data_map.size_cub, vars->data_map.map, vars->data);
	// draw_ray(vars->player.pov, vars->player, vars->data_map.map, vars->data);
	draw_3d(vars->player.pov, vars->player, vars->data_map.map, vars->data);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars		vars;
	t_data		data;
	t_player	player;
	t_data_map	data_map;
	t_keyboard	keyboard;

	vars.data = &data;
	vars.data_map = data_map;
	vars.player = player;
	vars.keyboard = keyboard;
	// vars = (t_vars *)malloc(sizeof(t_vars));

	char	map[10][10] = {
		'1', '1', '0', '1', '1', '1', '1', '1', '1', '1',
		'1', '0', '1', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '1', '1', '0', '1', '1', '0', '0', '1',
		'1', '0', '1', '1', '0', '1', '1', '0', '0', '1',
		'1', '0', '0', '0', 'N', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '1', '0', '0', '0', '1', '0', '0', '1',
		'1', '0', '0', '1', '1', '1', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'
	};

	vars.data_map.map = map;
	vars.data_map.map_len_x = 10;
	vars.data_map.map_len_y = 10;
	vars.data_map.size_cub = 64;

	vars.keyboard.A = 0;
	vars.keyboard.D = 0;
	vars.keyboard.S = 0;
	vars.keyboard.W = 0;
	vars.keyboard.left = 0;
	vars.keyboard.right = 0;

	vars.data->width = 1920;
	vars.data->height = 1080;
	vars.data->d = vars.data->width / (2 * tan(33 * M_PI / 180));
// Размер куба 64x64x64
	int		size_cub = 64;
// Для теста на двумерной карте, задаем параметры игрока
	vars.player.x = 5 * size_cub - 32;
	vars.player.y = 5 * size_cub - 32;
	vars.player.pov = 91;
	// vars.player = player;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.data->width, vars.data->height, "Hello");
	// mlx_key_hook(vars.win, key_hook, &vars);
	vars.data->img = mlx_new_image(vars.mlx, vars.data->width, vars.data->height);
	vars.data->addr = mlx_get_data_addr(vars.data->img, &(vars.data->bits_per_pixel), &(vars.data->line_length), &(vars.data->endian));// &img.bits_per_pixel, &img.line_length, &img.endian);

	// // Рисуем карту
	// // print_map(vars.data_map.map_len_x, vars.data_map.map_len_y, size_cub, map, vars.img);
	// // Рисуем лучи
	// // draw_ray(M_PI / 2, player, map, vars.img);

	// // mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_loop_hook(vars.mlx, &draw_game, &vars);
	mlx_hook(vars.win, 2, 0, &press_keyboard, &vars);
	mlx_hook(vars.win, 3, 0, &dismiss_keyboard, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
