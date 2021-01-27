/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:38 by skitsch           #+#    #+#             */
/*   Updated: 2021/01/27 11:42:40 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

t_collis	get_collision(t_data data)
{
	double	posX;
	double	posY;
	posX = 22;
	posY = 12;
	double	dirX; // вектор направления
	double	dirY;
	dirX = -1;
	dirY = 0;
	double	planeX;
	double	planeY;
	planeX = 0;
	planeY = 0.66;

	int		x;
	double	cameraX; // координата х в новой системе (-1,1)
	double	rayDirX; // вектор луча
	double	rayDirY;

	int		mapX;
	int		mapY;
	mapX = (int)posX;
	mapY = (int)posY;
	double	sideDistX; // первое соударение
	double	sideDistY;
	double	deltaDistX; // шаг для посследующих соударений
	double	deltaDistY;
	deltaDistX = (rayDirY == 0)? 0: ((rayDirX == 0)? 1: fabs(1 / rayDirX));//fabs(1 / rayDirX);
	deltaDistY = (rayDirX == 0)? 0: ((rayDirY == 0)? 1: fabs(1 / rayDirY));//fabs(1 / rayDirY);
	double	perpWallDist; // в каком направлении делать шаг: по x или по y (+1 или -1)
	int		stepX; // увеличение для mapX и mapY
	int		stepY;
	int		hit; // проверка, была ли стена?
	int		side; // был ли удар по стене NS или EW


	x = 0;
	while (x < data.width)
	{
		cameraX = 2 * x / (double)data.width - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		// вычисление шага и начальных координат sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		while (hit == 0)
		{

		}
		x++;
	}

}
