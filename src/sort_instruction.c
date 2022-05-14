/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 02:59:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/14 06:46:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

void	is_rr(int *tmp, t_list **stack_b, t_list **stack_a)
{
	int	rr;

	rr = 0;
	if (tmp[0] >= 0 && tmp[1] >= 0)
	{
		if (tmp[0] > tmp[1])
			rr = tmp[1];
		else
			rr = tmp[0];
	}
	tmp[0] -= rr;
	tmp[1] -= rr;
	while (rr)
	{
		ft_rr(stack_a, stack_b);
		rr--;
	}
}

void	is_rrr(int *tmp, t_list **stack_b, t_list **stack_a)
{
	int	rr;

	rr = 0;
	if (tmp[0] < 0 && tmp[1] < 0)
	{
		if (tmp[0] > tmp[1])
			rr = -tmp[0];
		else
			rr = -tmp[1];
	}
	tmp[0] += rr;
	tmp[1] += rr;
	while (rr)
	{
		ft_rrr(stack_a, stack_b);
		rr--;
	}
}

void	is_rbrrb(int *tmp, t_list **stack_b)
{
	if (tmp[0] > 0)
	{	
		while (tmp[0])
		{
			ft_rb(stack_b);
			tmp[0]--;
		}
	}
	else
	{
		tmp[0] *= -1;
		while (tmp[0])
		{
			ft_rrb(stack_b);
			tmp[0]--;
		}
	}
}

void	is_rarra(int *tmp, t_list **stack_a)
{
	if (tmp[1] > 0)
	{	
		while (tmp[1])
		{
			ft_ra(stack_a);
			tmp[1]--;
		}
	}
	else
	{
		tmp[1] *= -1;
		while (tmp[1])
		{
			ft_rra(stack_a);
			tmp[1]--;
		}
	}
}
