/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/11 02:58:51 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>



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
	int *tab;
	while (stack_b)
	{
		tab = push_back(stack_a,stack_b);
		is_rr(tab, &stack_b, &stack_a);
		is_rrr(tab, &stack_b, &stack_a);
		is_rbrrb(tab,&stack_b);
		is_rarra(tab,&stack_a);
		ft_pa(&stack_a,&stack_b);
		ft_bzero(tab,8);
		free(tab);
	}
	min_in_top_pr(&stack_a);
	return (ft_free(&stack_a),ft_free(&stack_b),0);
}