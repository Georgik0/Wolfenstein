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
	int		fd;

	line++;
	if (*(line++) != 'O')
		return (-1);
	if (vars->flags.NO == 1)
		return (-12); // параметр уже задан
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_left = ft_strdup(line)))
		return (-9);
	vars->flags.NO = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_south_texture(char *line, t_vars *vars)
{
	int		fd;

	if (vars->flags.SO == 1)
		return (-12); // параметр уже задан
	line++;
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_right = ft_strdup(line)))
		return (-11);
	vars->flags.SO = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_west_texture(char *line, t_vars *vars)
{
	int		fd;

	line++;
	if (*(line++) != 'E')
		return (-1);
	if (vars->flags.WE == 1)
		return (-12); // параметр уже задан
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_up = ft_strdup(line)))
		return (-10);
	vars->flags.WE = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_east_texture(char *line, t_vars *vars)
{
	int		fd;

	line++;
	if (*(line++) != 'A')
		return (-1);
	if (vars->flags.EA == 1)
		return (-12); // параметр уже задан
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_wall_down = ft_strdup(line)))
		return (-1);
	vars->flags.EA = 1;
	vars->flags.summ += 1;
	return (1);
}

int		get_sprite_texture(char *line, t_vars *vars)
{
	int		fd;

	if (vars->flags.S == 1)
		return (-12); // параметр уже задан
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(vars->dir_sprite = ft_strdup(line)))
		return (-15);
	vars->flags.S = 1;
	vars->flags.summ += 1;
	return (1);
}
