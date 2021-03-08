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

int		check_letter(char *line, t_vars *vars, int i)
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
		return (get_S(line, vars));
	else if (*line == '1')
		return (get_map_lst(line - i, vars));
	else
		return (-2);
}

int	check_line(char *line, t_vars *vars)
{
	int	out;
	int	i;

	i = 0;
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
	{
		i++;
		line++;
	}
	if (*line == '\0')
	{
		if (vars->flags.map_start == 1)
			vars->flags.map_end = 1;
		return (1);
	}
	out = check_letter(line, vars, i);
	return (out);
}

int	get_param(t_vars *vars, t_data_input *input_lst)
{
	t_data_input	*next;
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
	if (check_map(vars) == -1)
		return (-16);
	return (1);
}
