/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_north_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:40:04 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/02 17:40:06 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_north_texture(char *line, t_vars *vars)
{
	int		fd;

	if (*(++line) != 'O')
		return (-1);
	while (*line == ' ')
		line++;
	if (!(vars->dir_wall_left = ft_strdup(line)))
		return (-1);
	if ((fd = open(vars->dir_wall_left, O_RDONLY)) == -1)
	{
		free(vars->dir_wall_left);
		return (-1);
	}
	close(fd);
	return (1);
}
