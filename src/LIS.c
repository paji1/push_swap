/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:52:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/17 12:12:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

t_tab	*to_table(t_list *stackk, int size)
{
	t_tab *ss;
	t_list *stack;
	

	stack = stackk;
	ss = malloc(sizeof(t_tab));
	if (!stack || !ss)
		return (NULL);
	ss->i = 0;
	ss->tab = (int *)malloc(sizeof(int) * size);
	if (!ss->tab)
		return (NULL);
	ss->is = (int *)malloc(sizeof(int) * size);
	if (!(ss->is))
		return NULL;
	while (stack)
	{
		ss->is[(ss->i)] = 1;
		ss->tab[(ss->i)++] = stack->content;
		stack = stack->next;
	}
	return ss;
}

t_tab	*len_LIS(t_tab *ss)
{	
	int i;
	int j;
	int t;
	int temp;

	i = ss->i;
	j = i;
	while (--i >= 0)
	{
		temp = 0;
		t = i - 1;
		while (++t < j-1)
			if (ss->tab[i] < ss->tab[t+1] && ss->is[t+1] > temp)
				temp = ss->is[t+1];
		ss->is[i] +=temp;
	}
	return ss;
}

int *Lis_elem(t_tab *ss)
{
	int i;
	int big;
	int *n_tab;
	int temp;
	int count;

	i = 1;
	big = ss->is[0]- 1 ;
	n_tab = malloc(sizeof(int) * (big + 1));
	temp = 0;
	n_tab[0] = ss->tab[0];
	count = 1;
	while (big)
	{
		if(big == ss->is[i] && ss->tab[temp] < ss->tab[i])
		{
			n_tab[count++] = ss->tab[i];
			temp = i;
			big--;
		}
		i++;
	}
	return (free(ss->tab), free(ss->is),free(ss), n_tab);
}

int	push_nlis(t_list **stack_a, t_list **stack_b, int size_a)
{
	int		lis_size;
	t_tab	*ss;
	int		*tab;
	int		t;
	
	t = min_in_top(stack_a);
	ss = len_LIS(to_table((*stack_a), size_a));
	lis_size = ss->is[0];
	tab = Lis_elem(ss);
	min_toposition(stack_a,t);
	t = -1;
	while (++t < size_a)
	{
		if (!ft_in_table(tab, (*stack_a)->content,lis_size))
			ft_pb(stack_a,stack_b);
		else
			ft_ra(stack_a);
	}
	return  free(tab),lis_size;
}