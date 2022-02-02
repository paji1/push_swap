/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:09:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/02 14:47:09 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/pushSwap.h"
static void ft_instr(char *s, t_list **lsta, t_list **lstb)
{
	// static int i;
	if(!ft_strcmp(s, "pa\n"))
		ft_pa(lsta,lstb);
	if(!ft_strcmp(s, "pb\n"))
		ft_pb(lsta,lstb);
	if(!ft_strcmp(s, "ra\n"))
		ft_ra(lsta);
	if(!ft_strcmp(s, "ra\n"))
		ft_ra(lsta);
	if(!ft_strcmp(s, "rb\n"))
		ft_rb(lstb);
	if(!ft_strcmp(s, "rr\n"))
		ft_rr(lsta,lstb);
	if(!ft_strcmp(s, "rra\n"))
		ft_rra(lsta);
	if(!ft_strcmp(s, "rrb\n"))
		ft_rrb(lstb);
	if(!ft_strcmp(s, "rrr\n"))
		ft_rrr(lsta,lstb);
	if(!ft_strcmp(s, "sa\n"))
		ft_sa(lsta);
	if(!ft_strcmp(s, "sb\n"))
		ft_sa(lstb);
	if(!ft_strcmp(s, "ss\n"))
		ft_ss(lsta,lstb);
	
	

}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	char *s = "";
	handle(ac,av,&stack_a);
	while (*s != '\n')
	{
		s = get_next_line(1);
		ft_instr(s, &stack_a, &stack_b);
	}
	printf("\n##########   A    ################\n");
	while(stack_a)
	{
		printf("%d ",stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n##########   B    ################\n");
	while(stack_b)
	{
		printf("%d ",stack_b->content);
		stack_b = stack_b->next;
	}
	
	
	return 0;
}
