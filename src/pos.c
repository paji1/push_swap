/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:26:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/17 12:26:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
typedef struct s_pos
{
	int pos_b;
	int pos_a;
}t_pos;

int find_position(int element, t_list *stack)
{
	int i;
	t_list *temp;
	
	i = 0;
	temp = stack;
	if(!stack)
		return 0;
	while(temp && temp->content != element)
	{
		i++;
		temp = temp->next;
	}
	if (i >= stack->size / 2)
		return (i - stack->size);
	return (i + 1);
}

// int calcul_moves(t_pos pos)
// {
	
// }
