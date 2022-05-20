/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:43:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:15:12 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*pop(t_list **lst)
{
	t_list	*flst;

	if (!*lst)
		return (NULL);
	flst = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = flst->prev;
	return (flst);
}
