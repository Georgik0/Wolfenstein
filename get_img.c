/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:21:43 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/06 18:21:46 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_img_1(t_vars *vars)
{
	int		img_width;
	int		img_heigh;

	if (!(vars->data_array[3]->img = mlx_xpm_file_to_image(vars->mlx, vars->dir_wall_up, &img_width, &img_heigh)))
		return (-6);
	vars->data_array[3]->addr = mlx_get_data_addr(vars->data_array[3]->img, &(vars->data_array[3]->bits_per_pixel), &(vars->data_array[3]->line_length), &(vars->data_array[3]->endian));
	if (!(vars->data_array[4]->img = mlx_xpm_file_to_image(vars->mlx, vars->dir_wall_down, &img_width, &img_heigh)))
		return (-6);
	vars->data_array[4]->addr = mlx_get_data_addr(vars->data_array[4]->img, &(vars->data_array[4]->bits_per_pixel), &(vars->data_array[4]->line_length), &(vars->data_array[4]->endian));
	if (!(vars->data_array[5]->img = mlx_xpm_file_to_image(vars->mlx, vars->dir_sprite, &vars->data_array[5]->width, &vars->data_array[5]->height)))
		return (-6);
	vars->data_array[5]->addr = mlx_get_data_addr(vars->data_array[5]->img, &(vars->data_array[5]->bits_per_pixel), &(vars->data_array[5]->line_length), &(vars->data_array[5]->endian));
	return (1);
}

int		get_img(t_vars *vars)
{
	int		img_width;
	int		img_heigh;
	int		out;

	vars->mlx = mlx_init();
	vars->data_array[0]->img = mlx_new_image(vars->mlx, vars->data_array[0]->width, vars->data_array[0]->height);
	vars->data_array[0]->addr = mlx_get_data_addr(vars->data_array[0]->img, &(vars->data_array[0]->bits_per_pixel), &(vars->data_array[0]->line_length), &(vars->data_array[0]->endian));
	vars->win = mlx_new_window(vars->mlx, vars->data_array[0]->width, vars->data_array[0]->height, "cub3D");
	vars->data_array[0]->d = vars->data_array[0]->width / (2 * tan(33 * M_PI / 180));
	if (!(vars->data_array[1]->img = mlx_xpm_file_to_image(vars->mlx, vars->dir_wall_left, &img_width, &img_heigh)))
		return (-6);
	vars->data_array[1]->addr = mlx_get_data_addr(vars->data_array[1]->img, &(vars->data_array[1]->bits_per_pixel), &(vars->data_array[1]->line_length), &(vars->data_array[1]->endian));
	if (!(vars->data_array[2]->img = mlx_xpm_file_to_image(vars->mlx, vars->dir_wall_right, &img_width, &img_heigh)))
		return (-6);
	vars->data_array[2]->addr = mlx_get_data_addr(vars->data_array[2]->img, &(vars->data_array[2]->bits_per_pixel), &(vars->data_array[2]->line_length), &(vars->data_array[2]->endian));
	if ((out = get_img_1(vars)) != 1)
		return (out);
	return (1);
}
