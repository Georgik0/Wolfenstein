/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:29:30 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/07 19:29:32 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

int		reading_file1(t_data_input **input_lst,
char *line, int fd)
{
	if (add_line_in_lst(line, input_lst) == -1)
	{
		lst_clear(input_lst);
		close(fd);
		return (-4);
	}
	free(line);
	line = NULL;
	close(fd);
	return (1);
}

int		reading_file(char **argv, t_data_input **input_lst)
{
	char	*line;
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-3);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (add_line_in_lst(line, input_lst) == -1)
		{
			lst_clear(input_lst);
			close(fd);
			return (-4);
		}
		free(line);
		line = NULL;
	}
	if (reading_file1(input_lst, line, fd) == -4)
		return (-4);
	return (1);
}
