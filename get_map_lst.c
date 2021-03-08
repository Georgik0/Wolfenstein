/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:05:43 by skitsch           #+#    #+#             */
/*   Updated: 2021/03/03 21:05:45 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/my_type.h"

void	clear_map_lst(t_vars *vars)
{
	t_my_map	*next;

	while (vars->map_lst)
	{
		next = vars->map_lst->next;
		free(vars->map_lst->line);
		vars->map_lst->line = NULL;
		free(vars->map_lst);
		vars->map_lst = next;
	}
}

int		pars_map_lst(char *line, t_vars *vars)
{
	t_my_map	*new;
	t_my_map	*tmp;

	if (vars->map_lst == NULL)
	{
		if (!(vars->map_lst = (t_my_map *)malloc(sizeof(t_my_map))))
			return (-1);
		vars->map_lst->next = NULL;
		vars->map_lst->line = ft_strdup(line);
		vars->map_lst->length = ft_strlen(line);
		return (1);
	}
	else
	{
		tmp = vars->map_lst;
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!(new = (t_my_map *)malloc(sizeof(t_my_map))))
		return (-1);
	new->next = NULL;
	new->length = ft_strlen(line);
	new->line = ft_strdup(line);
	tmp->next = new;
	return (1);
}

int		get_map_lst(char *line, t_vars *vars)
{
	vars->flags.map_start = 1;
	if (pars_map_lst(line, vars) != 1)
	{
		clear_map_lst(vars);
		return (-16);
	}
	return (1);
}
