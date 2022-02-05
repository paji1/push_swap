/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:09:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/02 20:46:42 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/pushSwap.h"
static int ft_instr(char *s, t_list **lsta, t_list **lstb)
{
	if(!ft_strcmp(s, "pa\n"))
		ft_pa(lsta,lstb);
	else if(!ft_strcmp(s, "pb\n"))
		ft_pb(lsta,lstb);
	else if(!ft_strcmp(s, "ra\n"))
		ft_ra(lsta);
	else if(!ft_strcmp(s, "ra\n"))
		ft_ra(lsta);
	else if(!ft_strcmp(s, "rb\n"))
		ft_rb(lstb);
	else if(!ft_strcmp(s, "rr\n"))
		ft_rr(lsta,lstb);
	else if(!ft_strcmp(s, "rra\n"))
		ft_rra(lsta);
	else if(!ft_strcmp(s, "rrb\n"))
		ft_rrb(lstb);
	else if(!ft_strcmp(s, "rrr\n"))
		ft_rrr(lsta,lstb);
	else if(!ft_strcmp(s, "sa\n"))
		ft_sa(lsta);
	else if(!ft_strcmp(s, "sb\n"))
		ft_sa(lstb);
	else if(!ft_strcmp(s, "ss\n"))
		ft_ss(lsta,lstb);
	else
		return 1;
	return 0;
}


int Hi(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_temp;
	char 	*s;

	stack_a = NULL;
	stack_b = NULL;
	s = "";
	if(ac == 1)
		return 0;
	if(!handle(ac,av,&stack_a))
		return ft_free(&stack_a),ft_free(&stack_b),printf("error") , 0;
	while (*s != '\n')
	{
		s = get_next_line(1);
		if (ft_instr(s, &stack_a, &stack_b) && *s != '\n')
			return printf("error"),free(s),ft_free(&stack_a),ft_free(&stack_b),0;
		free(s);
	}
	stack_temp = stack_a;
	while(stack_temp)
	{
		if(stack_temp->next && stack_temp->content > stack_temp->next->content)
			return printf("Ko"),ft_free(&stack_a),ft_free(&stack_b),0;
		stack_temp = stack_temp->next;
	}
	return printf("OK"),ft_free(&stack_a),ft_free(&stack_b),0;
}
