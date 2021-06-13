/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:38:54 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/02 19:38:59 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_north_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'O')
		return (-1);
	if (vars->flags.no == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-9);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_up = ft_strdup(line)))
		return (-9);
	vars->flags.no = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_south_texture(char *line, t_vars *vars)
{
	if (vars->flags.so == 1)
		return (-12);
	line++;
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-11);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_down = ft_strdup(line)))
		return (-11);
	vars->flags.so = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_west_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'E')
		return (-1);
	if (vars->flags.we == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-10);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_left = ft_strdup(line)))
		return (-10);
	vars->flags.we = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_east_texture(char *line, t_vars *vars)
{
	line++;
	if (*(line++) != 'A')
		return (-1);
	if (vars->flags.ea == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-1);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_right = ft_strdup(line)))
		return (-1);
	vars->flags.ea = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_sprite_texture(char *line, t_vars *vars)
{
	if (vars->flags.s == 1)
		return (-12);
	if (!(*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r'))
		return (-15);
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_sprite = ft_strdup(line)))
		return (-15);
	vars->flags.s = 1;
	vars->flags.summ += 1;
	return (1);
}
