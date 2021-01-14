/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:33:29 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/14 14:33:32 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"
#include "mlx/mlx.h"

void	draw_ray(double pov, t_player player, char map[][10], t_data *img)
{
	t_collis	collis;
	double		phi = M_PI / 2;

	while (player.x < 600)
	{
		collis = find_collision(phi, player, map);
		print_line(player.x, player.y, collis.x, collis.y, img);
		player.x++;
	}
}
