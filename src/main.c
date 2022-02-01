/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/01 17:00:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>


int main(int ac, char **av)
{
	t_list	*stack_a;
	// t_list	*stack_b;
	// (void)av;
	// (void)ac;
	stack_a = NULL;
	// stack_b = NULL;
	// push(&stack_a, ft_lstnew(12));
	if(handle(ac,av,&stack_a))
		printf("%d",stack_a->prev->content);
	else
		printf("error");
	
	ft_free(&stack_a);
	// // ft_free(&stack_a);
	// ft_free(&stack_b);
	return (0);
	
}