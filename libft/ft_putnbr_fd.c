/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:27:43 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/04 19:27:45 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	write_putnbr(int dec, int n, int fd)
{
	char	num;
	int		buf;

	while (n - dec < 0)
		dec = dec / 10;
	while (n >= 0 && dec != 0)
	{
		buf = n / dec;
		num = buf + '0';
		write(fd, &num, 1);
		n = n - buf * dec;
		dec = dec / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int		dec;

	dec = 1000000000;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	write_putnbr(dec, n, fd);
}
