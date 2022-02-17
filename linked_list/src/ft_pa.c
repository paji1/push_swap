/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:56:01 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/16 15:14:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_pa(t_list **lsta, t_list **lstb)
{
	t_list *temp;
	
	if(!*lstb)
		return ;
	temp = pop(lstb);
	(*lstb)->size = (temp->size) - 1;
	push(lsta, ft_lstnew(temp->content));
	free(temp);
	write(1,"pa\n",3);
}