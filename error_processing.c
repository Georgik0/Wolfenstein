/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:37:50 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 18:37:52 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	error_processing(int error_code)
{
	if (error_code == -2)
		write(2, "incorrect input parameters\n", 27);
	else if (error_code == -3)
		write(2, "error when opening\n", 19);
	else if (error_code == -4)
		write(2, "error add line in lst\n", 22);
	else if (error_code == -5)
		write(2, "error malloc\n", 13);
	else if (error_code == -6)
		write(2, "error open xpm\n", 15);
	else if (error_code == -7)
		write(2, "invalid map\n", 12);
	else if (error_code == -8)
		write(2, "invalid screen param\n", 21);
	else if (error_code == -9)
		write(2, "errrrrrrrrrrr\n", 20);
}
