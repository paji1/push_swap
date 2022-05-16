/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/15 10:23:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
void stack_3(int size, t_list **stack_a)
{
	if (size != 3)
		return ;
	t_MIN min = find_min((*stack_a));
	if (min.index)
	{
		if (min.index == 2)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				ft_sa(stack_a);
				ft_rra(stack_a);
			}
		}
		else 
			if((*stack_a)->prev->content > (*stack_a)->content)
				ft_sa(stack_a);
	}
	else
	{
		if ((*stack_a)->prev->content < (*stack_a)->next->content)
		{
			ft_sa(stack_a);
			ft_ra(stack_a);
		}
	}
}
void stack_5(int size, t_list **stack_a, t_list **stack_b)
{
	t_MAX min;
	int *tab;
	
	if (size != 5)
		return ;
	// min = find_max(*stack_a);
	min = find_max(*stack_a);
	ft_pb(stack_a, stack_b);
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (1);
	if (!handle(ac, av, &stack_a))
		return (ptrf("Error\n", 2), ft_free(&stack_a), ft_free(&stack_b), 1);
	stack_5(stack_a->size, &stack_a, &stack_b);
	stack_3(stack_a->size, &stack_a);
	push_nlis(&stack_a, &stack_b, stack_a->size);
	while (stack_b)
	{
		tab = push_back(stack_a, stack_b);
		is_rr(tab, &stack_b, &stack_a);
		is_rrr(tab, &stack_b, &stack_a);
		is_rbrrb(tab, &stack_b);
		is_rarra(tab, &stack_a);
		ft_pa(&stack_a, &stack_b);
		ft_bzero(tab, 8);
		free(tab);
	}
	min_in_top_pr(&stack_a);
	// print_stack(stack_a,stack_b);
	return (ft_free(&stack_a), ft_free(&stack_b), 0);
}
