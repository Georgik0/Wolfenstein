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
		begin->str = NULL;
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
	clear_map_lst(vars);
	free(vars->map);
}

int	parser1(t_vars *vars, t_data_input **input_lst)
{
	int		out;
	if ((out = make_malloc_vars(vars)) != 1)
	{
		lst_clear(input_lst);
		return (out);
	}
	if ((out = get_param(vars, *input_lst)) != 1) // добавить обработку кода ошибки
	{
		lst_clear(input_lst);
		make_free_vars(vars);
		return (out);
	}
	lst_clear(input_lst);
	return (1);
}

int	parser(int argc, char **argv, t_vars *vars)
{
	int				out;
	t_data_input	*input_lst;

	if (argc != 2 && argc != 3)
		return (-2);
	if ((out = reading_file(argv, &input_lst)) != 1)
		return (out);
	if ((out = parser1(vars, &input_lst)) != 1)
		return (out);
	if ((out = get_img(vars)) != 1)
		return (out);
	if (argc == 3)
	{
		if ((out = make_screenshot(vars, argv)) != 1)
			return (out);
		make_free_vars(vars);
		exit (0);
	}
	return (1);
}
