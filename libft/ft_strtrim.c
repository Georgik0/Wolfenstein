/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:09:31 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/02 20:09:34 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check_set_first(char const *set, char const *s1)
{
	int i;
	int j;
	int flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	if (s1[i] == '\0' && flag == 1)
		return (-2);
	return (-1);
}

static	int		check_set_last(char const *set, char const *s1, int size_s1)
{
	int j;
	int flag;

	while (size_s1 >= 0)
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[size_s1] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (size_s1);
		size_s1--;
	}
	return (-1);
}

static	char	*fill_buf_strtrim(char const *s1,
				int first_entry, int last_entry)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc((last_entry - first_entry + 2) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (i < last_entry - first_entry + 1)
	{
		buf[i] = s1[first_entry + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		first_entry;
	int		last_entry;
	char	*buf;

	if (!s1)
		return (NULL);
	if (!set)
	{
		return (buf = ft_strdup(s1));
	}
	if ((first_entry = check_set_first(set, s1)) == -1)
	{
		buf = ft_strdup(s1);
		return (buf);
	}
	else if (first_entry == -2)
	{
		return (buf = ft_calloc(1, 1));
	}
	else
	{
		last_entry = check_set_last(set, s1, ft_strlen(s1) - 1);
		buf = fill_buf_strtrim(s1, first_entry, last_entry);
	}
	return (buf);
}
