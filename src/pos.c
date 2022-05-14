/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:26:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/14 06:31:45 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int	find_position(int element, t_list *stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack;
	if (!stack)
		return (0);
	while (temp && temp->content != element)
	{
		i++;
		temp = temp->next;
	}
	if (i >= stack->size / 2)
		return (i - stack->size);
	return (i + 1);
}
