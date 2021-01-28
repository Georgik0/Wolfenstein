/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:00:24 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/25 20:00:27 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"
#include "mlx/mlx.h"

void	draw_ray(double pov, t_player player, char (*map)[10], t_data *img)
{
	t_collis	collis;
	float		phi;
	float		new_phi;
	float		d_phi;

	phi = pov + 33;
	d_phi = 66.0 / 1920.0;
	while (phi > pov - 33)
	{
		if (phi < 0)
			new_phi = phi + 360;
		else if (phi > 360)
			new_phi = phi - 360;
		else
			new_phi = phi;


		collis = find_collision(new_phi * M_PI / 180, player, map);
		print_line(player.x, player.y, collis.x, collis.y, img);
		phi -= d_phi;
		// if (collis.x > 640 || collis.x < 0 || collis.y > 640 || collis.y < 0)
		// {
		// 	printf("x = %f  y = %f   pov = %f\n", collis.x, collis.y, pov);
		// }
	}
}

// void	draw_ray(double pov, t_player player, char (*map)[10], t_data *img)
// {
// 	t_collis	collis;
// 	float		phi;
// 	float		new_phi;
// 	float		d_phi;


// 	d_phi = 66.0 / 1920.0;
// 	collis = find_collision(pov * M_PI / 180, player, map);
// 	if (collis.x > 640 || collis.x < 0 || collis.y > 640 || collis.y < 0)
// 	{
// 		printf("x = %f  y = %f   pov = %f\n", collis.x, collis.y, pov);
// 	}
// 	// printf("pov = %f\n", pov);
// 	// print_line(player.x, player.y, collis.x, collis.y, img);
// }
