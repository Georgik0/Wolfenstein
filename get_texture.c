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
	while (*line == ' ')
		line++;
	if (!(vars->dir_wall_left = ft_strdup(line)))
		return (-1);
	printf("vars->dir_wall_left %s\n", vars->dir_wall_left);
	// if ((fd = open(vars->dir_wall_left, O_RDONLY)) == -1)
	// {
	// 	free(vars->dir_wall_left);
	// 	vars->dir_wall_left = NULL;
	// 	return (-1);
	// }
	// close(fd);
	return (1);
}

int		get_south_texture(char *line, t_vars *vars)
{
	int		fd;

	line++;
	while (*line == ' ')
		line++;
	if (!(vars->dir_wall_right = ft_strdup(line)))
		return (-1);
	printf("vars->dir_wall_right %s\n", vars->dir_wall_right);
	// if ((fd = open(vars->dir_wall_right, O_RDONLY)) == -1)
	// {
	// 	free(vars->dir_wall_right);
	// 	vars->dir_wall_right = NULL;
	// 	return (-1);
	// }
	// close(fd);
	return (1);
}

int		get_west_texture(char *line, t_vars *vars)
{
	int		fd;

	line++;
	if (*(line++) != 'E')
		return (-1);
	while (*line == ' ')
		line++;
	if (!(vars->dir_wall_up = ft_strdup(line)))
		return (-1);
	printf("vars->dir_wall_up %s\n", vars->dir_wall_up);
	// if ((fd = open(vars->dir_wall_up, O_RDONLY)) == -1)
	// {
	// 	free(vars->dir_wall_up);
	// 	vars->dir_wall_up = NULL;
	// 	return (-1);
	// }
	// close(fd);
	return (1);
}

int		get_east_texture(char *line, t_vars *vars)
{
	int		fd;

	line++;
	if (*(line++) != 'A')
		return (-1);
	while (*line == ' ')
		line++;
	if (!(vars->dir_wall_down = ft_strdup(line)))
		return (-1);
	printf("vars->dir_wall_down %s\n", vars->dir_wall_down);
	// if ((fd = open(vars->dir_wall_down, O_RDONLY)) == -1)
	// {
	// 	free(vars->dir_wall_down);
	// 	vars->dir_wall_down = NULL;
	// 	return (-1);
	// }
	// close(fd);
	return (1);
}

int		get_sprite_texture(char *line, t_vars *vars)
{
	int		fd;

	while (*line == ' ')
		line++;
	if (!(vars->dir_sprite = ft_strdup(line)))
		return (-1);
	printf("vars->dir_sprite %s\n", vars->dir_sprite);
	// if ((fd = open(vars->dir_sprite, O_RDONLY)) == -1)
	// {
	// 	free(vars->dir_sprite);
	// 	vars->dir_sprite = NULL;
	// 	return (-1);
	// }
	// close(fd);
	return (1);
}

int		get_S(char *line, t_vars *vars)
{
	int	out;
	line++;
	if (*line == 'O')
		out = get_south_texture(line, vars);
	else if (*line == ' ')
		out =get_sprite_texture(line, vars);
	else
		return (-1);
	return (out);
}
