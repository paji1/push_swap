/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 02:16:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/14 02:27:19 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

t_MAX	find_max(t_list *lst)
{
	t_MAX	max;
	int		i;

	i = 0;
	max.index = 0;
	max.lst = lst;
	max.num = lst->content;
	while (lst)
	{
		if (lst->content > max.lst->content)
		{
			max.lst = lst;
			max.num = lst->content;
			max.index = i;
		}
		i++;
		lst = lst->next;
	}
	return (max);
}

t_MIN	find_min(t_list *lst)
{
	t_MIN	min;
	int		i;

	i = 0;
	if (!lst)
		return (min.lst = NULL, min.index = 0, min);
	min.index = 0;
	min.lst = lst;
	min.num = lst->content;
	while (lst)
	{
		if (lst->content <= min.lst->content)
		{
			min.lst = lst;
			min.num = lst->content;
			min.index = i;
		}
		i++;
		lst = lst->next;
	}
	return (min);
}

int	i_mm(int min, int max, int first, int second)
{
	if (first == min)
	{
		if (second == max)
			return (1);
	}
	else if (first == max)
	{
		if (second == min)
			return (1);
	}
	return (0);
}
