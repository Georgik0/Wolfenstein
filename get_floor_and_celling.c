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

	i = 0;
	if (param == NULL)
		return (-1);
	if (*param == '\0')
		return (-1);
	while (param[i])
	{
		if (ft_isdigit(param[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		pars_color(char **param, t_vars *vars)
{
	int	R;
	int	G;
	int	B;
	int	color;

	if (check_digit(param[0]) == -1 || check_digit(param[1]) == -1 || check_digit(param[2]) == -1)
		return (-1);
	if (ft_strlen(param[0]) > 3 || ft_strlen(param[1]) > 3 || ft_strlen(param[2]) > 3)
		return (-1);
	if ((R = ft_atoi(param[0])) > 255)
		return (-1);
	if ((G = ft_atoi(param[1])) > 255)
		return (-1);
	if ((B = ft_atoi(param[2])) > 255)
		return (-1);
	color = 256 * 256 * R + 256 * G + B;
	return (color);
}

int		get_floor_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.F == 1)
		return (-12);
	line++;
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	if (num_screen_param(param) == -3)
	{
		clear_param(param);
		return (-13);
	}
	if ((vars->color_floor = pars_color(param, vars)) == -1)
	{
		clear_param(param);
		return (-13);
	}
	vars->flags.F = 1;
	vars->flags.summ += 1;
	clear_param(param);
	return (1);
}

int		get_ceilling_color(char *line, t_vars *vars)
{
	char	**param;

	if (vars->flags.C == 1)
		return (-12);
	line++;
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	param = ft_split(line, ',');
	if (num_screen_param(param) == -3)
	{
		clear_param(param);
		return (-14);
	}
	if ((vars->color_ceilling = pars_color(param, vars)) == -1)
	{
		clear_param(param);
		return (-14);
	}
	vars->flags.C = 1;
	vars->flags.summ += 1;
	clear_param(param);
	return (1);
}
