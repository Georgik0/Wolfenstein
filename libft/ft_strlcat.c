/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:42:45 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 12:42:48 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t start;
	size_t dst_size;

	if (size == 0)
		return (ft_strlen(src));
	start = 0;
	while (dst[start] && start < size)
		start++;
	dst_size = start;
	j = 0;
	while (start < size - 1 && src[j])
	{
		dst[start] = src[j];
		start++;
		j++;
	}
	if (dst_size < size)
		dst[start] = '\0';
	return (dst_size + ft_strlen(src));
}
