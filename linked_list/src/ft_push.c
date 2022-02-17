/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:17:44 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/16 14:41:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	push(t_list **lst, t_list *new)
{
	static t_list	*tmp;
	
	if((*lst) == NULL)
		tmp = NULL;
	new->next = *lst;
	*lst = new;
	if(!((*lst)->next))
		(*lst)->size = 0;
	if(tmp)
	{
		if(tmp != (*lst)->next->prev)
			tmp = (*lst)->next->prev;
		(*lst)->next->prev = *(lst);
	}
	else
		tmp = new;
	(*lst)->prev = tmp;
	if ((*lst) && (*lst)->next)
		(*lst)->size = (*lst)->next->size + 1;
	else if ((*lst) && !((*lst)->next))
		(*lst)->size = 1;
}
