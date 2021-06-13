/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_and_celling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:49:20 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/03 12:49:22 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

static int		check_digit(char *param)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (param == NULL)
		return (-1);
	if (*param == '\0')
		return (-1);
	while (param[i] == ' ' || param[i] == '\t' || param[i] == '\f'
	|| param[i] == '\v' || param[i] == '\r')
		i++;
	while (ft_isdigit(param[i++]) != 0)
		count++;
	while (param[i] == ' ' || param[i] == '\t'
	|| param[i] == '\f' || param[i] == '\v' || param[i] == '\r')
		i++;
	if (param[i] != '\0')
		return (-1);
	if (count > 3)
		return (-1);
	return (1);
}

int				pars_color(char **param)
{
	int	r;
	int	g;
	int	b;
	int	color;

	if (check_digit(param[0]) == -1 || check_digit(param[1]) == -1 ||
	check_digit(param[2]) == -1)
		return (-1);
	if ((r = ft_atoi(param[0])) > 255)
		return (-1);
	if ((g = ft_atoi(param[1])) > 255)
		return (-1);
	if ((b = ft_atoi(param[2])) > 255)
		return (-1);
	color = 256 * 256 * r + 256 * g + b;
	return (color);
}

int				check_comma(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		if (count > 2)
			return (-1);
		str++;
	}
	return (1);
}

int				get_floor_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.f == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-13);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	if (check_comma(line) == -1 || num_screen_param(param) != 3 ||
	(vars->color_floor = pars_color(param)) == -1)
	{
		clear_param(param);
		return (-13);
	}
	vars->flags.f = 1;
	vars->flags.summ += 1;
	clear_param(param);
	return (1);
}

int				get_ceilling_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.c == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-14);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	if (check_comma(line) == -1 || num_screen_param(param) != 3 ||
	(vars->color_ceilling = pars_color(param)) == -1)
	{
		clear_param(param);
		return (-14);
	}
	vars->flags.c = 1;
	vars->flags.summ += 1;
	clear_param(param);
	return (1);
}
