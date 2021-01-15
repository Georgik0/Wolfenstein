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
#include <stdio.h>

void	draw_ray(double pov, t_player player, char map[][10], t_data *img)
{
	t_collis	collis;
	float		phi;
	double		d_phi;

	pov = 90;
	phi = pov + 33;// * M_PI / 180;
	d_phi = 66.0 / 1920.0;// * M_PI / 180;
	// printf ("%f\n", phi);
	while (phi > pov - 33)// * M_PI / 180)
	{
		// phi = phi + d_phi;
		// printf("радиан phi = %f\n", phi);
		// printf("градус phi = %f\n", phi * 180 / M_PI);
		collis = find_collision(nearbyint(phi * M_PI / 180), player, map);
		// printf("phi = %f x = %d  y = %d\n", phi, collis.x, collis.y);
		print_line(player.x, player.y, collis.x, collis.y, img);
		phi -= d_phi;
		// printf("phi = %f", phi);
	}
}
