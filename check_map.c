/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:06:40 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/04 15:06:42 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		check_up(char **map, int x, int y)
{
	if (y == 0)
		return (-1);
	while (y-- > 0)
	{
		if (x > ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_bottom(char **map, int x, int y, int length_map_y)
{
	if (y == length_map_y - 1)
		return (-1);
	while (y++ < length_map_y - 1)
	{
		if (x > ft_strlen(map[y]) - 1)
			return (-1);
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_left(char **map, int x, int y)
{
	if (x == 0)
		return (-1);
	while (x-- > 0)
	{
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_right(char **map, int x, int y)
{
	if (x == ft_strlen(map[y]) - 1)
		return (-1);
	while (x-- > 0)
	{
		if (map[y][x] == '1')
			return (1);
	}
	return (-1);
}

int		check_valid(t_vars *vars, int x, int y)
{
	if (check_up(vars->map, x, y) == -1 ||
	check_bottom(vars->map, x, y, vars->length_map_y) == -1 ||
	check_left(vars->map, x, y) == -1 ||
	check_right(vars->map, x, y) == -1)
	{
		return (-1);
	}
	return (1);
}

int		check_player(t_vars *vars, char direction, int x, int y)
{
	if (vars->player.check == 1)
		return (-1);
	vars->player.check = 1;
	vars->player.x = x * 64 + 32;
	vars->player.y = y * 64 + 32;
	// printf("player:    x = %d   y = %d\n", vars->player.x, vars->player.y);
	if (direction == 'N')
	{
		// printf("N\n");
		vars->player.pov = 90.0;
	}
	else if (direction == 'W')
	{
		// printf("W\n");
		vars->player.pov = 180.0;
	}
	else if (direction == 'S')
		vars->player.pov = 270.0;
	else
		vars->player.pov = 0.0;
	return (1);
}

static int		check_line(t_vars *vars, char *line, int y)
{
	int		x;
	int		out;

	x = 0;
	out = 1;
	while (line[x++])
	{
		if (line[x] == '1' || line[x] == ' ' || line[x] == '\0')
			continue ;
		else if (line[x] == '2' || line[x] == '0')
		{
			if (check_valid(vars, x, y) == -1)
				return (-1);
		}
		else if (line[x] == 'N' || line[x] == 'W' ||
		line[x] == 'S' || line[x] == 'E')
		{
			// printf("test\n");
			if (check_valid(vars, x, y) == -1)
				return (-1);
			if (check_player(vars, line[x], x, y) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	return (1);
}

int		check_map(t_vars *vars)
{
	int		y;

	y = 0;
	while (vars->map[y])
	{
		// printf("$%s\n", vars->map[y]);
		if (check_line(vars, vars->map[y], y) == -1)
			return (-1);
		y++;
	}
	return (1);
}
