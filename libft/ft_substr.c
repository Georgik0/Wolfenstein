/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:23:49 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 17:23:52 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*buf;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		buf = ft_calloc(1, 1);
		return (buf);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	buf = (char *)malloc((i + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
