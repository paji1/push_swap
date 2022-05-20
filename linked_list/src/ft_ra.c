/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:14:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:17:30 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_ra_rr(t_list **lst)
{
	t_list	*temp;

	if (!*lst)
		return ;
	if (!((*lst)->next))
		return ;
	temp = NULL;
	temp = pop(lst);
	(*lst)->size = temp->size;
	ft_lstadd_back(lst, ft_lstnew(temp->content));
	free(temp);
}

void	ft_ra(t_list **lst)
{
	if (!*lst)
		return ;
	if (!((*lst)->next))
		return ;
	ft_ra_rr(lst);
	write(1, "ra\n", 3);
}
