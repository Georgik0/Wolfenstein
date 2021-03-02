/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:37:38 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/01 20:37:41 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_west_texture(char *line, t_vars *vars)
{
	return (0);
}

int		get_east_texture(char *line, t_vars *vars)
{
	return (0);
}

int		get_floor_color(char *line, t_vars *vars)
{
	return (0);
}

int		get_ceilling_color(char *line, t_vars *vars)
{
	return (0);
}

int		get_S(char *line, t_vars *vars)
{
	return (0);
}

int		get_map(char *line, t_vars *vars)
{
	return (0);
}

int		check_letter(char *line, t_vars *vars)
{
	if (*line == 'R')
		return (get_screen_param(line, vars));
	else if (*line == 'N')
		return (get_north_texture(line, vars));
	else if (*line == 'W')
		return (get_west_texture(line, vars));
	else if (*line == 'E')
		return (get_east_texture(line, vars));
	else if (*line == 'F')
		return (get_floor_color(line, vars));
	else if (*line == 'C')
		return (get_ceilling_color(line, vars));
	else if (*line == 'S')
		return (get_S(line, vars));
	else if (*line == '1')
		return (get_map(line, vars));
	else
		return (-1);
}

int	check_line(char *line, t_vars *vars)
{
	int	out;
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (*line == '\0')
		return (0);
	out = check_letter(line, vars);
	return (out);
}

int	get_param(t_vars *vars, t_data_input *input_lst)
{
	while (input_lst)
	{
		if (check_line(input_lst->str, vars) == -1)
			return (-1);
		input_lst = input_lst->next;
	}
	return (0);
}
