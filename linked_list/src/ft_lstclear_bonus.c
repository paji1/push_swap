/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:43:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/13 18:25:12 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	if (!lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
	}
}
