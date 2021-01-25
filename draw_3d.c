/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:59:18 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/25 19:59:20 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"
#include "mlx/mlx.h"

void	draw_vertical_line(int length, t_data *img)
{

}

void	draw_3d(int pov, t_player player, char (*map)[10], t_data *img)
{
	int			length;
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


		length = get_length(new_phi * M_PI / 180, player, map);

		phi -= d_phi;
	}
}
