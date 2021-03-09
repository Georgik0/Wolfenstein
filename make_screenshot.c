/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:07:20 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/05 17:07:22 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void		fill_header(int fd, int summary_size)
{
	unsigned char	header_bmp[14];

	header_bmp[0] = 'B';
	header_bmp[1] = 'M';
	header_bmp[2] = summary_size;
	header_bmp[3] = summary_size >> 8;
	header_bmp[4] = summary_size >> 16;
	header_bmp[5] = summary_size >> 24;
	header_bmp[6] = 0;
	header_bmp[7] = 0;
	header_bmp[8] = 0;
	header_bmp[9] = 0;
	header_bmp[10] = 54;
	header_bmp[11] = 0;
	header_bmp[12] = 0;
	header_bmp[13] = 0;
	write(fd, header_bmp, 14);
}

void		fill_information(int fd, t_vars *vars)
{
	unsigned char	info_header_bmp[40];
	int				i;

	info_header_bmp[0] = 40;
	info_header_bmp[1] = 0;
	info_header_bmp[2] = 0;
	info_header_bmp[3] = 0;
	info_header_bmp[4] = vars->data_array[0]->width;
	info_header_bmp[5] = vars->data_array[0]->width >> 8;
	info_header_bmp[6] = vars->data_array[0]->width >> 16;
	info_header_bmp[7] = vars->data_array[0]->width >> 24;
	info_header_bmp[8] = vars->data_array[0]->height;
	info_header_bmp[9] = vars->data_array[0]->height >> 8;
	info_header_bmp[10] = vars->data_array[0]->height >> 16;
	info_header_bmp[11] = vars->data_array[0]->height >> 24;
	info_header_bmp[12] = 1;
	info_header_bmp[13] = 0;
	info_header_bmp[14] = 32;
	i = 15;
	while (i < 40)
		info_header_bmp[i++] = 0;
	write(fd, info_header_bmp, 40);
}

void		fill_images(int fd, t_vars *vars)
{
	int					y_xpm;
	int					x_xpm;
	int					color;

	y_xpm = vars->data_array[0]->height - 1;
	while (y_xpm >= 0)
	{
		x_xpm = 0;
		while (x_xpm < vars->data_array[0]->width)
		{
			color = *(int*)(vars->data_array[0]->addr +
			(y_xpm * vars->data_array[0]->line_length +
			x_xpm * (vars->data_array[0]->bits_per_pixel / 8)));
			write(fd, &color, 4);
			x_xpm += 1;
		}
		y_xpm--;
	}
}

int			make_screenshot(t_vars *vars, char **argv)
{
	int			fd;
	int			summary_size;
	int			offset;

	draw_3d(vars);
	offset = (4 - (vars->data_array[0]->width * 3) % 4) % 4;
	summary_size = 14 + 40 +
	vars->data_array[0]->width * vars->data_array[0]->height * 3 +
	offset * vars->data_array[0]->height;
	if (ft_strncmp("--save", argv[2], 7) != 0)
		return (-2);
	if ((fd = open("screen.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
		return (-3);
	fill_header(fd, summary_size);
	fill_information(fd, vars);
	fill_images(fd, vars);
	return (1);
}
