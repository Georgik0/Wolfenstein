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

int		key_hook(int keycode, t_vars *vars)
{
	// printf("Hello from key_hook!\n");
	// mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 13)
		vars->player->y -= 1;
	if (keycode == 1)
		vars->player->y += 1;
	if (keycode == 0)
		vars->player->x -= 1;
	if (keycode == 2)
		vars->player->x += 1;
	return (0);
}

// int		cleek(int key, t_player player, t_vars vars)
// {
// 	mlx_clear_window(vars.mlx, vars.win);
// 	if (key == 13)
// 		player.y -= 1;
// 	if (key == 1)
// 		player.y += 1;
// 	if (key == 0)
// 		player.x -= 1;
// 	if (key == 2)
// 		player.x += 1;
// 	return (0);
// }

void	print_map(int map_len_x, int map_len_y, int size_cub, char map[][10], t_data *img)
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
			j++;
		}
		i++;
	}
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

int	main(void)
{
	t_vars	vars;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_player	player;

	char	map[10][10] = {
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
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

// Размер куба 32x32x32
	int		size_cub = 32;
// Для теста на двумерной карте
	size_cub = 64;
	player.x = 4 * size_cub - 32;
	player.y = 7 * size_cub - 32;
	float	pov = 0;
	int		map_len_x = 10;
	int		map_len_y = 10;

	vars.player = &player;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello");
	mlx_key_hook(vars.win, key_hook, &vars);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// Рисуем карту
	print_map(map_len_x, map_len_y, size_cub, map, &img);
	// Рисуем лучи
	draw_ray(M_PI / 2, player, map, &img);
	// print_line(228, 128, 100, 128, &img);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
