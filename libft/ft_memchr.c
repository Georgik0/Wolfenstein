/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:39:56 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:39:59 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*s;

	u_c = (unsigned char)c;
	s = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (s[i] == u_c)
			return (s + i);
		i++;
	}
	return (NULL);
}
