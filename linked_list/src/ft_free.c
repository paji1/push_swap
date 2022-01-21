/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:09:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/18 00:04:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>
void ft_free(t_list **lst)
{
	t_list	*temp1;

	if (!*lst)
		return ;
	temp1 = (*lst)->prev;
	while(temp1 != (*lst) && temp1)
	{
		temp1 = temp1->prev;
		free(temp1->next);
	}	
	free(temp1);
}
