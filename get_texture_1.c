/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:38:47 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/03 12:38:49 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		get_S(char *line, t_vars *vars)
{
	int	out;
	line++;
	if (*line == 'O')
		out = get_south_texture(line, vars);
	else if (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		out =get_sprite_texture(line, vars);
	else
		return (-1);
	return (out);
}
