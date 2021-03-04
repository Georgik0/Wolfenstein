/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:15:06 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/01 15:15:08 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	lst_clear(t_data_input **input_lst)
{
	t_data_input *begin;
	t_data_input *next_list;

	begin = *input_lst;
	while (begin)
	{
		next_list = begin->next;
		free(begin->str);
		free(begin);
		begin = next_list;
	}
	*input_lst = NULL;
}

int		add_line_in_lst(char *line, t_data_input **input_lst)
{
	t_data_input	*new_lst;
	t_data_input	*tmp;

	if (*input_lst == NULL)
	{
		if (!(*input_lst = (t_data_input *)malloc(sizeof(t_data_input))))
			return (-1);
		(*input_lst)->next = NULL;
		if (!((*input_lst)->str = ft_strdup(line)))
		{
			free(input_lst);
			return (-1);
		}
	}
	else
	{
		if (!(new_lst = (t_data_input *)malloc(sizeof(t_data_input))))
			return (-1);
		new_lst->next = NULL;
		if (!(new_lst->str = ft_strdup(line)))
		{
			free(new_lst);
			return (-1);
		}
		tmp = *input_lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_lst;
	}
	return (0);
}

void	make_free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	free(vars->data);
	while (i < 6)
	{
		free(vars->data_array[i]);
		vars->data_array[i] = NULL;
		i++;
	}
	free(vars->data_array);
	free(vars->dir_sprite);
	free(vars->dir_wall_down);
	free(vars->dir_wall_left);
	free(vars->dir_wall_right);
	free(vars->dir_wall_up);
}

int	parser(int argc, char **argv, t_vars *vars)
{
	int				fd;
	char			*line;
	t_data_input	*input_lst;

	if (argc != 2)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	line = NULL;
	input_lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (add_line_in_lst(line, &input_lst) == -1)
		{
			lst_clear(&input_lst);
			close(fd);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	close(fd);
	if (make_malloc_vars(vars) == -1)
	{
		lst_clear(&input_lst);
		return (-1);
	}
	if (get_param(vars, input_lst) == -1) // добавить обработку кода ошибки
	{
		lst_clear(&input_lst);
		make_free_vars(vars);
		return (-1);
	}
	lst_clear(&input_lst);
	// t_data_input	*iter;
	// iter = input_lst;
	// while (iter)
	// {
	// 	printf("%s\n", iter->str);
	// 	iter = iter->next;
	// }
	return (0);
}
