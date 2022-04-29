/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/27 15:08:36 by tel-mouh         ###   ########.fr       */
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


	
	stack_a = NULL;
	stack_b = NULL;
	if(ac <= 1)
		return 0;
	if(!handle(ac,av,&stack_a))
		return printf("error"), ft_free(&stack_a), ft_free(&stack_b), 1;
	push_nlis(&stack_a,&stack_b,stack_a->size);

	print_stack(stack_a,stack_b);
	printf("\npos_a -> %d\n", find_position(234,stack_b));
	// free(tab);
	printf("%d ",stack_b->size);
	return (ft_free(&stack_a),ft_free(&stack_b),0);
}