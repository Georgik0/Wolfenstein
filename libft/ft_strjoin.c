/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:23:41 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 18:23:43 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if ((buf = (char *)malloc((size1 + size2) * sizeof(char) + 1)) == NULL)
		return (NULL);
	buf[size2 + size1] = '\0';
	if (size1 == 0)
		ft_strlcpy(buf, s1, size1);
	else
		ft_strlcpy(buf, s1, size1 + 1);
	if (size2 != 0)
		size2++;
	ft_strlcpy(buf + size1, s2, size2);
	return (buf);
}
