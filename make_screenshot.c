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

void	fill_header(int fd)
{
	write(fd, "424D\n", 5); // тип файла
	write(fd, "00000000\n", 9); // размер файла
	write(fd, "0000\n", 5); // Reserved
	write(fd, "0000\n", 5); // Reserved
	write(fd, "36000000\n", 9); // 0x36 = 54 - общее значение заголовков
	write(fd, "28000000\n", 9); // HeaderSize
	write(fd, "05000000\n", 9); // ImageWidth
	write(fd, "05000000\n", 9); // ImageHeight
	write(fd, "0100\n", 5); // Planes
	write(fd, "1800\n", 5); // BitsPerPixel
	write(fd, "00000000\n", 9);
	write(fd, "00000000\n", 9);
	write(fd, "00000000\n", 9);
	write(fd, "00000000\n", 9);
	write(fd, "00000000\n", 9);
	write(fd, "00000000\n", 9);
}

void	fill_images(int fd)
{
	write(fd, "00000000000000000000000000000000\n", 33);
	write(fd, "00000000000000000000000000000000\n", 33);
	write(fd, "00000000000000000000000000000000\n", 33);
	write(fd, "00000000000000000000000000000000\n", 33);
	write(fd, "00000000000000000000000000000000\n", 33);
}

int		make_screenshot(t_vars *vars, char **argv)
{
	int		fd;

	if (ft_strncmp("--save", argv[2], 6) != 0)
		return (-1);
	if ((fd = open("screen.bmp", O_CREAT | O_EXCL | O_TRUNC | O_WRONLY, 0666)) == -1)
		return (-1);
	fill_header(fd);
	fill_images(fd);
	return (1);
}
