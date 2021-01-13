/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:40:40 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:40:43 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)arr1)[i] - ((unsigned char*)arr2)[i] != 0)
			return ((unsigned char*)arr1)[i] - ((unsigned char*)arr2)[i];
		i++;
	}
	return (0);
}
