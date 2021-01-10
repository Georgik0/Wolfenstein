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

// void	test_write(t_data **)
// {

// }

void	print_map(int map_len_x, int map_len_y, int size_cub, char map[][10], t_data *img)
{
	int		i = 0;
	int		j = 0;
	int		max_X = map_len_x * size_cub;
	int		max_Y = map_len_y * size_cub;

	while (i < max_X)
	{
		j = 0;
		while (j < max_Y)
		{
			if (map[j / size_cub][i / size_cub] == '1')
				my_mlx_pixel_put(img, i, j, 0xFF6347);
			j++;
		}
		i++;
	}
}

void	print_player(int playerX, int playerY, char map[][10], t_data *img)
{
	my_mlx_pixel_put(img, playerX, playerY, 0x7CFC00);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	char	map[10][10] = {
		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
		'1', '0', '0', '0', '0', '0', '0', '0', '0', '1',
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
	int		playerX = 5 * size_cub;
	int		playerY = 5 * size_cub;
	float	pov = M_PI / 2;
	int		map_len_x = 10;
	int		map_len_y = 10;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// Рисуем карту
	print_map(map_len_x, map_len_y, size_cub, map, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
