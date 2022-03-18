/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/18 03:24:02 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>

// static void set_index(t_list **stack_a,t_hash *hash)
// {
// 	t_list	*temp;
	
// 	temp = *stack_a;
// 	while (temp)
// 	{
// 		temp->content = find_key(temp->content, hash);
// 		temp = temp->next;
// 	}
// }




int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	// t_hash *hash;
	// t_hash *sorted_hash;

	
	stack_a = NULL;
	stack_b = NULL;
	if(ac <= 1)
		return 0;
	if(!handle(ac,av,&stack_a))
		return printf("error"), ft_free(&stack_a), ft_free(&stack_b), 1;
	size_a = stack_a->size;
	push_nlis(&stack_a,&stack_b,size_a);
	// inis_hash(&hash,stack_a);
	// sort_hash(&sorted_hash,stack_a,stack_a->size);
	// set_index(&stack_a,sorted_hash);
	
	// print_stack(stack_a,stack_b);
	// free(tab);
	return (ft_free(&stack_a),ft_free(&stack_b),0);
}