/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:57:32 by skitsch           #+#    #+#             */
/*   Updated: 2020/11/09 17:57:35 by skitsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *begin;
	t_list *next_list;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		next_list = begin->next;
		del(begin->content);
		free(begin);
		begin = next_list;
	}
	*lst = NULL;
}
