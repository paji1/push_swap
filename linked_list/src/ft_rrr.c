/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:35:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:21:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra_rr(stack_a);
	ft_rrb_rr(stack_b);
	write(1, "rrr\n", 4);
}

void	ft_rrr_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rra_rr(stack_a);
	ft_rrb_rr(stack_b);
}
