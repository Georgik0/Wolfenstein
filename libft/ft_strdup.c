/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:57:24 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/06 17:57:25 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = ft_strlen(s1);
	len++;
	out = (char *)malloc(len * sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, s1, len);
	return (out);
}
