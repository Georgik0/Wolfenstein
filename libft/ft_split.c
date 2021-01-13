/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:44:21 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/03 12:44:23 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			get_len(const char *s, char c)
{
	int i;
	int size;
	int flag;

	i = 0;
	size = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			size++;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (size);
}

static	int			*get_len_mas(const char *s, int size, char c)
{
	int *len_mas;
	int i;
	int j;

	if ((len_mas = (int*)malloc(size * sizeof(int))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len_mas[j] = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				len_mas[j]++;
				i++;
			}
			len_mas[j]++;
			j++;
			i--;
		}
		i++;
	}
	return (len_mas);
}

static	char		**make_malloc(int *len_mas, int size)
{
	int		i;
	char	**out;

	i = 0;
	if ((out = (char **)malloc((size + 1) * sizeof(char*))) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((out[i] = (char *)malloc(len_mas[i] * sizeof(char))) == NULL)
		{
			while (i >= 0)
			{
				free(out[i]);
				i--;
			}
			free(out);
			return (NULL);
		}
		i++;
	}
	out[size] = NULL;
	free(len_mas);
	return (out);
}

static	void		feel_out(char **out, char c, const char *s)
{
	int i;
	int j;
	int k;
	int size;

	i = 0;
	k = 0;
	size = get_len(s, c);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
			{
				out[k][j] = s[i];
				i++;
				j++;
			}
			out[k][j] = '\0';
			k++;
			i--;
		}
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char	**out;
	int		*len_mas;

	if (!s)
		return (NULL);
	else
	{
		if ((get_len(s, c)) != 0)
		{
			if ((len_mas = get_len_mas(s, get_len(s, c), c)) == NULL)
				return (NULL);
			if ((out = make_malloc(len_mas, get_len(s, c))) == NULL)
			{
				free(len_mas);
				return (NULL);
			}
			feel_out(out, c, s);
			return (out);
		}
		if ((out = (char **)malloc(sizeof(char*))) == NULL)
			return (NULL);
		out[0] = NULL;
	}
	return (out);
}
