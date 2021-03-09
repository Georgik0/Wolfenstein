/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:30:10 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/02 11:30:11 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		num_screen_param(char **screen)
{
	int	len;

	len = 0;
	while (*screen)
	{
		len++;
		screen++;
	}
	return (len);
}

int		check_digit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*(str++)) == 0)
			return (0);
	}
	return (1);
}

int		get_width(char *str, t_vars *vars)
{
	int	width;

	while (*str == '0')
		str++;
	if (*str == '\0')
	{
		vars->data_array[0]->width = MIN_WIDTH;
		return (1);
	}
	if (check_digit(str))
	{
		if (ft_strlen(str) > 5)
			vars->data_array[0]->width = MAX_WIDTH;
		else if ((width = ft_atoi(str)) >= MAX_WIDTH)
			vars->data_array[0]->width = MAX_WIDTH;
		else if (width <= MIN_WIDTH)
			vars->data_array[0]->width = MIN_WIDTH;
		else
			vars->data_array[0]->width = width;
		return (1);
	}
	else
		return (-1);
	return (1);
}

int		get_height(char *str, t_vars *vars)
{
	int	height;

	while (*str == '0')
		str++;
	if (*str == '\0')
	{
		vars->data_array[0]->height = MIN_HEIGHT;
		return (1);
	}
	if (check_digit(str))
	{
		if (ft_strlen(str) > 5)
			vars->data_array[0]->height = MAX_HEIGHT;
		else if ((height = ft_atoi(str)) >= MAX_HEIGHT)
			vars->data_array[0]->height = MAX_HEIGHT;
		else if (height <= MIN_HEIGHT)
			vars->data_array[0]->height = MIN_HEIGHT;
		else
			vars->data_array[0]->height = height;
		return (1);
	}
	else
		return (-1);
	return (1);
}

int		get_screen_param(char *line, t_vars *vars)
{
	char	**screen;

	screen = ft_split(line, ' ');
	if (num_screen_param(screen) != 3)
	{
		clear_param(screen);
		return (-8);
	}
	if ((get_width(screen[1], vars)) == -1)
	{
		clear_param(screen);
		return (-8);
	}
	if (get_height(screen[2], vars) == -1)
	{
		clear_param(screen);
		return (-8);
	}
	clear_param(screen);
	return (1);
}
