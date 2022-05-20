/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:47:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:28:53 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_sb(t_list **lst)
{
	t_list	*temp;
	t_list	*temp1;

	temp = NULL;
	temp1 = NULL;
	if (!(*lst) || !((*lst)->next))
		return ;
	temp = pop(lst);
	temp1 = pop(lst);
	push(lst, temp);
	push(lst, temp1);
	write(1, "sb\n", 3);
}

void	ft_sb_rr(t_list **lst)
{
	t_list	*temp;
	t_list	*temp1;

	temp = NULL;
	temp1 = NULL;
	if (!(*lst) || !((*lst)->next))
		return ;
	temp = pop(lst);
	temp1 = pop(lst);
	push(lst, temp);
	push(lst, temp1);
}
