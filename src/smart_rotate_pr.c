/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate_pr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:47:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/11 00:42:31 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int smart_rotate_pr(t_list **stack_a,int condition,int i)
{
	void	(*rotate)(t_list **);
	int		count;

	count = 0;
	if (condition)
		rotate = &ft_ra;
	else
		rotate = &ft_rra;
	while((*stack_a)->content != i)
	{
		if(condition)
			count++;
		else
			count--;
		rotate(stack_a);
	}
	return (count);
}



int min_in_top_pr(t_list **stack_a)
{
	t_MIN	min;
	int		min_content;
	int		r;

	r = 0;
	min = find_MIN(*stack_a);
	min_content = min.lst->content;
	r = smart_rotate_pr(stack_a,min.index < ((*stack_a)->size - 1)/ 2,min_content);
	return (r);
}
