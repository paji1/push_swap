/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:09:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 21:07:07 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

static int	ft_instr(char *s, t_list **lsta, t_list **lstb)
{
	if (!ft_strcmp(s, "rra\n"))
		ft_rra_rr(lsta);
	else if (!ft_strcmp(s, "rrb\n"))
		ft_rrb_rr(lstb);
	else if (!ft_strcmp(s, "rrr\n"))
		ft_rrr_rr(lsta, lstb);
	else if (!ft_strcmp(s, "sa\n"))
		ft_sa_rr(lsta);
	else if (!ft_strcmp(s, "sb\n"))
		ft_sb_rr(lstb);
	else if (!ft_strcmp(s, "ss\n"))
		ft_ss_rr(lsta, lstb);
	else
		return (1);
	return (0);
}

static int	ft_instr2(char *s, t_list **lsta, t_list **lstb)
{
	if (!ft_strcmp(s, "pa\n"))
		ft_pa_rr(lsta, lstb);
	else if (!ft_strcmp(s, "pb\n"))
		ft_pb_rr(lsta, lstb);
	else if (!ft_strcmp(s, "ra\n"))
		ft_ra_rr(lsta);
	else if (!ft_strcmp(s, "rra\n"))
		ft_rra_rr(lsta);
	else if (!ft_strcmp(s, "rb\n"))
		ft_rb_rr(lstb);
	else if (!ft_strcmp(s, "rr\n"))
		ft_rr_rr(lsta, lstb);
	else
		return (1);
	return (0);
}

int	check_stack(t_list *stack_temp, t_list **stack_a, t_list **stack_b)
{
	while (stack_temp->next)
	{
		if (stack_temp->next && stack_temp->content > stack_temp->next->content)
			return (ft_putstr_fd("KO\n", 1), ft_free(stack_a), \
				ft_free(stack_b), 1);
		stack_temp = stack_temp->next;
	}
	return (0);
}

int	manipulte_stacks(t_list **stack_a, t_list **stack_b, char *s)
{
	while (*s != '\n')
	{
		s = get_next_line(1);
		if (!s)
			return (ft_putstr_fd("Error\n", 1), ft_free(stack_a), \
				ft_free(stack_b), 1);
		if ((ft_instr(s, stack_a, stack_b) && ft_instr2(s, stack_a, stack_b)) \
			&& *s != '\n')
			return (ft_putstr_fd("Error\n", 1), free(s), ft_free(stack_a), \
				ft_free(stack_b), 1);
		if (*s == '\n')
		{
			free(s);
			break ;
		}
		free(s);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*s;

	stack_a = NULL;
	stack_b = NULL;
	s = "";
	if (ac == 1)
		return (1);
	if (!handle(ac, av, &stack_a))
		return (ft_free(&stack_a), ft_free(&stack_b), \
			ft_putstr_fd("Error\n", 1), 1);
	if (manipulte_stacks(&stack_a, &stack_b, s))
		return (1);
	if (check_stack(stack_a, &stack_a, &stack_b))
		return (1);
	if (stack_b && stack_b->size)
		return (ft_putstr_fd("KO", 1), ft_free(&stack_a), ft_free(&stack_b), 1);
	return (ft_putstr_fd("OK", 1), ft_free(&stack_a), ft_free(&stack_b), 0);
}
