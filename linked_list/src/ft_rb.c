/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:14:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/16 15:04:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void ft_rb_rr(t_list **lst)
{
	t_list *temp;

	if (!*lst)
		return ;
	if(!((*lst)->next))
		return ;
	temp = pop(lst);
	(*lst)->size++;
	ft_lstadd_back(lst, ft_lstnew(temp->content));
	free(temp);
}
void	ft_rb(t_list **lst)
{
	if(!((*lst)->next))
		return ;
	ft_rb_rr(lst);
	write(1,"rb\n",3);
}