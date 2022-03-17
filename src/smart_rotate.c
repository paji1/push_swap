/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:47:38 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/16 23:48:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

void smart_rotate(t_list **stack_a,int condition,int i)
{
	void (*rotate)(t_list **);

	if (condition)
		rotate = &ft_ra;
	else
		rotate = &ft_rra;
	
	while((*stack_a)->content != i)
		rotate(stack_a);
	
	
}

void min_in_top(t_list **stack_a)
{

	t_MIN	min;
	int		min_content;

	min = find_MIN(*stack_a);
	min_content = min.lst->content;
	smart_rotate(stack_a,min.index < ((*stack_a)->size - 1)/ 2,min_content);
}