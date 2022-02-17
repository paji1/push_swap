/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/16 15:25:01 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>

static void set_index(t_list **stack_a,t_hash *hash)
{
	t_list	*temp;
	
	temp = *stack_a;
	while (temp)
	{
		temp->content = find_key(temp->content, hash);
		temp = temp->next;
	}
}
void smart_rotate(t_list **stack_a,int condition,t_list *elem)
{
	void (*rotate)(t_list **);

	if (condition)
		rotate = &ft_ra;
	else
		rotate = &ft_rra;
	while((*stack_a)->content != elem->content)
	{
		rotate(stack_a);
	}
}

void min_in_top(t_list **stack_a)
{

	t_MIN min = find_MIN(*stack_a);
	smart_rotate(stack_a,min.index <= ((*stack_a)->size - 1)/ 2,min.lst);
}


int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_hash *hash;
	t_hash *sorted_hash;

	
	
	stack_a = NULL;
	stack_b = NULL;
	if(ac <= 1)
		return 0;
	if(!handle(ac,av,&stack_a))
		return printf("error"), ft_free(&stack_a), ft_free(&stack_b), 1;
	inis_hash(&hash,stack_a);
	sort_hash(&sorted_hash,stack_a,stack_a->size);
	set_index(&stack_a,sorted_hash);
	min_in_top(&stack_a);
	
	// ft_pb(&stack_a,&stack_b);
	printf("sa = %d  \n", stack_a->size);
	print_stack(stack_a,stack_b);
	
	return (ft_free(&stack_a),0);
	
}