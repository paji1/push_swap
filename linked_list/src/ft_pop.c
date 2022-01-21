/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:43:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/16 00:35:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*pop(t_list **lst)
{
	if(!*lst)
		return NULL;
	t_list * flst = *lst;
	*lst = (*lst)->next;
	if((*lst))
		(*lst)->prev = flst->prev;
	return flst;
}