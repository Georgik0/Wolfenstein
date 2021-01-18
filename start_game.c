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

void	print_map(int map_len_x, int map_len_y, int size_cub, char (*map)[11], t_data *img)
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

int		change_coord(int keycode, t_vars *vars)
{
	if (keycode == 13)
	{
		vars->player.y -= 1; 	//player->y -= 1;
		// vars->player.x += (int)nearbyint(cos(vars->player.pov / 180 * M_PI));
	}
	if (keycode == 1)
	{
		vars->player.y += 1;
		// vars->player.x += (int)nearbyint(cos(vars->player.pov / 180 * M_PI));
	}
	if (keycode == 0)
		vars->player.pov += 1;	//player->x -= 1;
	if (keycode == 2)
		vars->player.pov -= 1;	//player->x += 1;
	if (vars->player.pov >= 360)
		vars->player.pov -= 360;
	if (vars->player.pov < 0)
		vars->player.pov += 360;
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
	print_map(vars->data_map.map_len_x, vars->data_map.map_len_y, vars->data_map.size_cub, vars->data_map.map, vars->img);
	draw_ray(vars->player.pov, vars->player, vars->data_map.map, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	// t_player	player;

	vars = (t_vars *)malloc(sizeof(t_vars));

	char	map[10][11] = {
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0',
		'1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '\0',
		'1', '0', '1', '1', '0', '1', '1', '0', '0', '1', '\0',
		'1', '0', '1', '1', '0', '1', '1', '0', '0', '1', '\0',
		'1', '0', '0', '0', 'N', '0', '0', '0', '0', '1', '\0',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0',
		'1', '0', '1', '0', '0', '0', '1', '0', '0', '1', '\0',
		'1', '0', '0', '1', '1', '1', '0', '0', '0', '1', '\0',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '\0',
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '\0'
	};

	vars->data_map.map = map;
	vars->data_map.map_len_x = 10;
	vars->data_map.map_len_y = 10;
	vars->data_map.size_cub = 64;

	// vars.keyboard.A = 0;
	// vars.keyboard.D = 0;
	// vars.keyboard.S = 0;
	// vars.keyboard.W = 0;
	// vars.A = 0;
	// vars.D = 0;
	// vars.S = 0;
	// vars.W = 0;
// Размер куба 64x64x64
	int		size_cub = 64;
// Для теста на двумерной карте, задаем параметры игрока
	vars->player.x = 4 * size_cub - 32;
	vars->player.y = 7 * size_cub - 32;
	vars->player.pov = 2;
	// vars.player = player;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello");
	// mlx_key_hook(vars.win, key_hook, &vars);
	// vars->img->img = mlx_new_image((*vars).mlx, 1920, 1080);
	// vars->img->addr = mlx_get_data_addr(vars->img->img, &(vars->img->bits_per_pixel), &(vars->img->line_length), &(vars->img->endian));// &img.bits_per_pixel, &img.line_length, &img.endian);

	// // Рисуем карту
	// // print_map(vars.data_map.map_len_x, vars.data_map.map_len_y, size_cub, map, vars.img);
	// // Рисуем лучи
	// // draw_ray(M_PI / 2, player, map, vars.img);

	// // mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	// mlx_loop_hook(vars.mlx, &draw_game, &vars);
	// mlx_hook(vars.win, 2, 0, &change_coord, &vars);
	mlx_loop(vars->mlx);
	return (0);
}
