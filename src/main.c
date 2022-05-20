/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 21:21:09 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int	stack_3(int size, t_list **stack_a)
{
	t_MIN	min;

	min = find_min(*stack_a);
	if (min.index)
	{
		if (min.index == 2)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
				return (ft_sa(stack_a), ft_rra(stack_a), 0);
		}
		else
			if ((*stack_a)->prev->content > (*stack_a)->content)
				ft_sa(stack_a);
	}
	else
	{
		if ((*stack_a)->prev->content < (*stack_a)->next->content)
			return (ft_sa(stack_a), ft_ra(stack_a), 0);
	}
	return (1);
}

void	stack_5(int size, t_list **stack_a, t_list **stack_b)
{	
	if (size == 5)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		stack_3(size, stack_a);
	}
	if (size == 3)
		stack_3(size, stack_a);
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
		return (ft_putstr_fd("Error\n", 2), ft_free(&stack_a) \
			, ft_free(&stack_b), 1);
	stack_5(stack_a->size, &stack_a, &stack_b);
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
	return (min_in_top_pr(&stack_a), ft_free(&stack_a), ft_free(&stack_b), 0);
}
