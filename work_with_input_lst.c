/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_input_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:12:06 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/08 16:12:15 by skitsch          ###   ########.fr       */
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

int		create_input_lst(char *line, t_data_input **input_lst)
{
	if (!(*input_lst = (t_data_input *)malloc(sizeof(t_data_input))))
		return (-1);
	(*input_lst)->next = NULL;
	if (!((*input_lst)->str = ft_strdup(line)))
	{
		free(input_lst);
		return (-1);
	}
	return (1);
}

int		add_line_in_lst(char *line, t_data_input **input_lst)
{
	t_data_input	*new_lst;
	t_data_input	*tmp;

	if (*input_lst == NULL)
	{
		if (create_input_lst(line, input_lst) == -1)
			return (-1);
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
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	return (1);
}
