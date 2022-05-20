/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:35:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:19:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra_rr(stack_a);
	ft_rb_rr(stack_b);
	write(1, "rr\n", 3);
}

void	ft_rr_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra_rr(stack_a);
	ft_rb_rr(stack_b);
}
