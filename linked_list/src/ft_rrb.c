/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:15:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:20:43 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_rrb_rr(t_list **lst)
{
	t_list	*last;

	if (!(*lst) || !((*lst)->next))
		return ;
	last = (*lst)->prev;
	(*lst)->prev = (*lst)->prev->prev;
	push(lst, ft_lstnew(last->content));
	(*lst)->size--;
	(*lst)->prev = last->prev;
	(*lst)->prev->next = NULL;
	free(last);
}

void	ft_rrb(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return ;
	ft_rrb_rr(lst);
	write(1, "rrb\n", 4);
}
