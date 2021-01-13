/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:40:54 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:40:57 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t i;

	i = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)destination)[i] = ((unsigned char*)source)[i];
		i++;
	}
	return (destination);
}
