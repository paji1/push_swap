/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:24:55 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/10 01:21:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int ft_isin(t_list *lst,int content)
{
	int i;

	i = 0;
	while(lst)
	{
		if (lst->content == content)
			return i; 
		lst = lst->next;
		i++;
	}
	return -1;
}