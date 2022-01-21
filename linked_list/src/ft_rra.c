/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:15:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/19 08:08:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void ft_rra(t_list **lst)
{
	t_list *last;

	if(!(*lst) || !((*lst)->next))
		return ;
	last = (*lst)->prev;
	(*lst)->prev = (*lst)->prev->prev;
	push(lst, ft_lstnew(last->content));
	(*lst)->prev = last->prev;
	(*lst)->prev->next = NULL;
	free(last);
}