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

int		check_letter(char *line, t_vars *vars)
{
	if (*line == '1' && vars->flags.map_end == 1)
		return (-7);
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
		return (get_s(line, vars));
	else
		return (-2);
}

int		check_line(char *line, t_vars *vars)
{
	int	out;
	int	i;

	i = 0;
	if (*line == '1' || *line == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			vars->flags.map_start = 1;
			out = get_map_lst(line, vars);
			return (out);
		}
	}
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (*line == '\0')
	{
		if (vars->flags.map_start == 1)
			vars->flags.map_end = 1;
		return (1);
	}
	return (check_letter(line, vars));
}

int		get_param(t_vars *vars, t_data_input *input_lst)
{
	int				out;

	while (input_lst)
	{
		if ((out = check_line(input_lst->str, vars)) != 1)
		{
			return (out);
		}
		input_lst = input_lst->next;
	}
	get_map(vars);
	if ((out = check_map(vars)) != 1)
		return (out);
	return (1);
}
