/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:56:01 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:13:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_pb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!*lsta)
		return ;
	temp = pop(lsta);
	(*lsta)->size = (temp->size) - 1;
	push(lstb, ft_lstnew(temp->content));
	free(temp);
	write(1, "pb\n", 3);
}

void	ft_pb_rr(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!*lsta)
		return ;
	temp = pop(lsta);
	(*lsta)->size = (temp->size) - 1;
	push(lstb, ft_lstnew(temp->content));
	free(temp);
}
