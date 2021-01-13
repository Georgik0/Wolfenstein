/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:39:36 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:39:42 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		if (((unsigned char *)source)[i] == (unsigned char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
