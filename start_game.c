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
	if (vars->data_map.map[(vars->player.x + delta_x) / 64]
	[(vars->player.y + delta_y) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
	}
	if (vars->data_map.map[(vars->player.x + delta_x) / 64]
	[(vars->player.y) / 64] != '1')
		vars->player.x += delta_x;
	if (vars->data_map.map[(vars->player.x) / 64]
	[(vars->player.y + delta_y) / 64] != '1')
		vars->player.y += delta_y;
}

void	change_coord_S(t_vars *vars)
{
	int	delta_x;
	int	delta_y;

	delta_x = -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
	delta_y = (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
	if (vars->data_map.map[(vars->player.x + delta_x) / 64]
	[(vars->player.y + delta_y) / 64] != '1')
	{
		vars->player.x += delta_x;
		vars->player.y += delta_y;
	}
	if (vars->data_map.map[(vars->player.x + delta_x) / 64]
	[(vars->player.y) / 64] != '1')
		vars->player.x += delta_x;
	if (vars->data_map.map[(vars->player.x) / 64]
	[(vars->player.y + delta_y) / 64] != '1')
		vars->player.y += delta_y;
}

// void	change_coord_A(t_vars *vars)
// {
// 	int	delta_x;
// 	int	delta_y;

// 	delta_x = -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
// 	delta_y = (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
// }

// void	change_coord_D(t_vars *vars)
// {

// }

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
	{
		// vars->player.x += (int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
		// vars->player.y += -(int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
		change_coord_W(vars);
	}
	if (vars->keyboard.S)
	{
		// vars->player.x += -(int)nearbyint(cos(vars->player.pov * M_PI / 180) * 3);
		// vars->player.y += (int)nearbyint(sin(vars->player.pov * M_PI / 180) * 3);
		change_coord_S(vars);
	}
	if (vars->keyboard.A)
		vars->player.x -= 1;
	if (vars->keyboard.D)
		vars->player.x += 1;
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
	draw_3d(vars->player.pov, vars->player, vars->data_map.map, vars->data, vars->data_array);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	// mlx_do_sync(vars->mlx);
	return (0);
}

int	main(void)
{
	t_vars		vars;
	t_data		data;
	t_player	player;
	t_data_map	data_map;
	t_keyboard	keyboard;
	t_data		data_wall_left;
	t_data		data_wall_right;
	t_data		data_wall_up;
	t_data		data_wall_down;
	t_data		**data_array;
	char		*dir_wall_left = "./texture/WALL32.xpm";
	char		*dir_wall_right = "./texture/WALL53.xpm";
	char		*dir_wall_up = "./texture/WALL88.xpm";
	char		*dir_wall_down = "./texture/WALL89.xpm";
	int			img_width;
	int			img_heigh;

	vars.data = &data;
	vars.data_map = data_map;
	vars.player = player;
	vars.keyboard = keyboard;
	// vars = (t_vars *)malloc(sizeof(t_vars));

	char	map[10][10] = {
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
		'1', '1', '0', '0', '0', '0', '0', '0', '1', '1',
		'1', '0', '2', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
		'1', '1', '0', '0', '0', '0', '0', '0', '1', '1',
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
	vars.player.x = 1 * size_cub + 32;
	vars.player.y = 6 * size_cub + 32;
	vars.player.pov = 90;

	vars.mlx = mlx_init();

	// Получаем текстуры
	if (!(data_array = (t_data**)malloc(5 * sizeof(t_data*))))
		exit(0);
	data_array[0] = &data;
	data_array[1] = &data_wall_left;
	data_array[2] = &data_wall_right;
	data_array[3] = &data_wall_up;
	data_array[4] = &data_wall_down;
	data_wall_left.img = mlx_xpm_file_to_image(vars.mlx, dir_wall_left, &img_width, &img_heigh);
	data_wall_right.img = mlx_xpm_file_to_image(vars.mlx, dir_wall_right, &img_width, &img_heigh);
	data_wall_up.img = mlx_xpm_file_to_image(vars.mlx, dir_wall_up, &img_width, &img_heigh);
	data_wall_down.img = mlx_xpm_file_to_image(vars.mlx, dir_wall_down, &img_width, &img_heigh);

	data_wall_left.addr = mlx_get_data_addr(data_wall_left.img, &(data_wall_left.bits_per_pixel), &(data_wall_left.line_length), &(data_wall_left.endian));
	data_wall_right.addr = mlx_get_data_addr(data_wall_right.img, &(data_wall_right.bits_per_pixel), &(data_wall_right.line_length), &(data_wall_right.endian));
	data_wall_up.addr = mlx_get_data_addr(data_wall_up.img, &(data_wall_up.bits_per_pixel), &(data_wall_up.line_length), &(data_wall_up.endian));
	data_wall_down.addr = mlx_get_data_addr(data_wall_down.img, &(data_wall_down.bits_per_pixel), &(data_wall_down.line_length), &(data_wall_down.endian));

	vars.data_array = data_array; // передали массив со всеми t_data

	vars.win = mlx_new_window(vars.mlx, vars.data->width, vars.data->height, "Hello");

	vars.data->img = mlx_new_image(vars.mlx, vars.data->width, vars.data->height);
	vars.data->addr = mlx_get_data_addr(vars.data->img, &(vars.data->bits_per_pixel), &(vars.data->line_length), &(vars.data->endian));// &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx_loop_hook(vars.mlx, &draw_game, &vars);
	mlx_hook(vars.win, 2, 0, &press_keyboard, &vars);
	mlx_hook(vars.win, 3, 0, &dismiss_keyboard, &vars);
	mlx_do_sync(vars.mlx);
	mlx_loop(vars.mlx);
	return (0);
}
