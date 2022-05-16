/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:47:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/15 07:29:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"


void ft_sa(t_list **lst)
{
	t_list *temp;
	t_list *temp1;
	
	temp = NULL;
	temp1 = NULL;
	if(!(*lst) || !((*lst)->next))
		return ;
	temp = pop(lst);
	temp1 = pop(lst);
	push(lst,temp);
	push(lst,temp1);
	write(1,"sa\n",3);
}