/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:41:15 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:41:19 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t				i;

	if (!destination && !source)
		return (NULL);
	if ((unsigned char*)destination < (const unsigned char*)source)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char*)destination)[i] =
			((const unsigned char*)source)[i];
			i++;
		}
	}
	else if ((unsigned char*)destination > (const unsigned char*)source)
	{
		while (n > 0)
		{
			((unsigned char*)destination)[n - 1] =
			((const unsigned char*)source)[n - 1];
			n--;
		}
	}
	return (destination);
}
