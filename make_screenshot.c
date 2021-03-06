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

void	fill_header(int fd, int summary_size)
{
	unsigned char	header_bmp[14];

	header_bmp[0] = (unsigned char)'B';
	header_bmp[1] = (unsigned char)'M';
	header_bmp[2] = (unsigned char)summary_size;
	header_bmp[3] = (unsigned char)summary_size >> 8;
	header_bmp[4] = (unsigned char)summary_size >> 16;
	header_bmp[5] = (unsigned char)summary_size >> 24;
	header_bmp[6] = (unsigned char)0;
	header_bmp[7] = (unsigned char)0;
	header_bmp[8] = (unsigned char)0;
	header_bmp[9] = (unsigned char)0;
	header_bmp[10] = (unsigned char)54;
	header_bmp[11] = (unsigned char)0;
	header_bmp[12] = (unsigned char)0;
	header_bmp[13] = (unsigned char)0;
	write(fd, header_bmp, 14);
}

void	fill_information(int fd, t_vars *vars)
{
	unsigned char	info_header_bmp[40];
	int				i;

	info_header_bmp[0] = (unsigned char)40;
	info_header_bmp[1] = (unsigned char)0;
	info_header_bmp[2] = (unsigned char)0;
	info_header_bmp[3] = (unsigned char)0;
	info_header_bmp[4] = (unsigned char)vars->data_array[0]->width;
	info_header_bmp[5] = (unsigned char)vars->data_array[0]->width >> 8;
	info_header_bmp[6] = (unsigned char)vars->data_array[0]->width >> 16;
	info_header_bmp[7] = (unsigned char)vars->data_array[0]->width >> 24;
	info_header_bmp[8] = (unsigned char)vars->data_array[0]->height;
	info_header_bmp[9] = (unsigned char)vars->data_array[0]->height >> 8;
	info_header_bmp[10] = (unsigned char)vars->data_array[0]->height >> 16;
	info_header_bmp[11] = (unsigned char)vars->data_array[0]->height >> 24;
	info_header_bmp[12] = (unsigned char)1;
	info_header_bmp[13] = (unsigned char)0;
	info_header_bmp[14] = (unsigned char)4;
	i = 15;
	while (i < 40)
		info_header_bmp[i++] = 0;
	write(fd, info_header_bmp, 40);
}

void	fill_images(int fd, t_vars *vars)
{
	int					y_xpm;
	int					x_xpm;
	unsigned int		color;

	x_xpm = 0;
	while (x_xpm < vars->data_array[0]->width)
	{
		y_xpm = vars->data_array[0]->height - 1;
		while (y_xpm >= 0)
		{
			color = *(int*)(vars->data_array[0]->addr + (y_xpm * vars->data_array[0]->line_length / 4 + x_xpm));
			// printf("%x\n", color);
			write(fd, &color, 4);
			y_xpm--;
		}
		x_xpm++;
	}

}

int		make_screenshot(t_vars *vars, char **argv)
{
	int			fd;
	int			summary_size;
	int			offset;

	draw_3d(vars);
	offset = (4 - (vars->data_array[0]->width * 3) % 4) % 4;
	summary_size = 14 + 40 +
	vars->data_array[0]->width * vars->data_array[0]->height * 3 +
	offset * vars->data_array[0]->height;

	if (ft_strncmp("--save", argv[2], 6) != 0)
		return (-1);
	if ((fd = open("screen.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
		return (-1);
	fill_header(fd, summary_size);
	printf("test\n");
	fill_information(fd, vars);
	fill_images(fd, vars);
	return (1);
}
