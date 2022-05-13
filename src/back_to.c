/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:19:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/13 06:23:44 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int	calculemoves(int *tmp)
{
	int	moves;

	moves = 0;
	if (tmp[0] > 0 && tmp[1] > 0)
	{
		if (tmp[0] >= tmp[1])
			moves = tmp[0];
		else
			moves = tmp[1];
	}
	else if (tmp[0] < 0 && tmp[1] < 0)
	{
		if (tmp[0] >= tmp[1])
			moves = -tmp[1];
		else
			moves = -tmp[0];
	}
	else
	{
		if (tmp[0] < tmp[1])
			moves = tmp[1] - tmp[0];
		else
			moves = tmp[0] - tmp[1];
	}
	return (moves);
}

void	best_move(int *tmp, int *best)
{
	if (calculemoves(best) > calculemoves(tmp))
		ft_memcpy(best, tmp, 8);
}

int	*push_back(t_list *stack_a, t_list *stack_b)
{
	int	*best;
	int	tmp[2];

	best = (int *)malloc(sizeof(int) * 4);
	loop_front(tmp, best, stack_a, stack_b);
	loop_back(tmp, best, stack_a, stack_b);
	return (best);
}

int	is_bettwen(int first, int num, int second)
{
	if (first < num && num < second)
		return (1);
	else if (first > num && num > second)
		return (1);
	return (0);
}

int	get_a(t_list *stack, int content)
{
	int			i;
	int			j;
	int			t;
	t_MIN_MAX	mn;

	i = 0;
	j = -1;
	t = 0;
	mn.max = find_MAX(stack);
	mn.min = find_MIN(stack);
	if (is_bettwen(stack->content, content, stack->prev->content))
		if (!i_MM(mn.min.num, mn.max.num, stack->content, \
			stack->prev->content))
			return (0);
	t = lood_a_front(stack, &i, content, mn);
	j = lood_a_back(stack, &t, content, mn);
	if (i > stack->size / 2 && - j > stack->size / 2)
		return (t);
	if (i < -j)
		return (i);
	else
		return (j);
	return (0);
}
