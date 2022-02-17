/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:56:01 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/16 15:14:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_pb(t_list **lsta, t_list **lstb)
{
	t_list *temp;
	
	if(!*lsta)
		return ;
	temp = pop(lsta);
	(*lsta)->size = (temp->size) - 1;
	push(lstb, ft_lstnew(temp->content));
	free(temp);
	write(1,"pb\n",3);
}