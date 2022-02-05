/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 02:16:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/04 02:19:02 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pushSwap.h"

t_MAX find_MAX(t_list *lst)
{
	t_MAX	max;
	int 	i;
	
	i = 0;
	
	max.index = 0;
	max.lst = lst;
	while (lst)
	{
		if(lst->content > max.lst->content)
		{
			max.lst = lst;
			max.index = i;
		}
		i++;
		lst = lst->next;
	}
	return max;
}
t_MIN	find_MIN(t_list *lst)
{
	t_MIN	min;
	int 	i;
	
	i = 0;
	
	min.index = 0;
	min.lst = lst;
	while (lst)
	{
		if(lst->content < min.lst->content)
		{
			min.lst = lst;
			min.index = i;
		}
		i++;
		lst = lst->next;
	}
	return min;
}
