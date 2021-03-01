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

int	check_line(char *line)
{
	while (*line == ' ' || *line == '\t' || *line == '\f'
	|| *line == '\v' || *line == '\r')
		line++;
	if (!(*line))
		return(0);
}

int	get_param(t_vars *vars, t_data_input *input_lst)
{
	// t_data_input *iter;

	// iter =
	while (input_lst)
	{

		input_lst = input_lst->next;
	}

}
