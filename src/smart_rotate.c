/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:47:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/01 23:44:13 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int smart_rotate(t_list **stack_a,int condition,int i)
{
	void	(*rotate)(t_list **);
	int		count;

	count = 0;
	if (condition)
		rotate = &ft_ra_rr;
	else
		rotate = &ft_rra_rr;
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

int min_in_top(t_list **stack_a)
{
	t_MIN	min;
	int		min_content;
	int		r;

	r = 0;
	min = find_MIN(*stack_a);
	min_content = min.lst->content;
	r = smart_rotate(stack_a,min.index < ((*stack_a)->size - 1)/ 2,min_content);
	return (r);
}

void min_toposition(t_list **stack_a,int cr)
{
	int count;

	count = cr;
	while(count-- > 0 && cr > 0)
		ft_rra_rr(stack_a);
	while(++count < 0 && cr < 0)
		ft_ra_rr(stack_a);
}

int search_bt(t_list **stack, int *nlist, int len)
{
	int i;
	int size;
	t_list *last;
	t_list *head;

	i = -1;
	size = (*stack)->size;
	head = *stack;
	last = (*stack)->prev; 
	while(++i < size / 2)
	{
		if (!ft_in_table(nlist,head->content,len))
			return smart_rotate(stack,1,head->content), 1;
		else if (!ft_in_table(nlist,last->content,len))
			return smart_rotate(stack,0,last->content), 1;
		head = head->next;
		last = last->prev;
	}
	return 0;
}
