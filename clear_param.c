/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:10:10 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/09 18:10:13 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	clear_param(char **screen)
{
	int	i;

	i = 0;
	while (screen[i])
	{
		free(screen[i]);
		screen[i] = NULL;
		i++;
	}
	free(screen);
}
