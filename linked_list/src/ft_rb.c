/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:14:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/19 08:08:58 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void ft_rb(t_list **lst)
{
	t_list *temp;

	if(!((*lst)->next))
		return ;
	temp = pop(lst);
	ft_lstadd_back(lst, ft_lstnew(temp->content));
	free(temp);
}