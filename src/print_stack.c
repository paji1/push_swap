/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:25:40 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/03 20:18:17 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
void print_stack(t_list *lsta, t_list *lstb)
{
	printf("\n## stack_a ##				## stack_b ##\n\n\n");
	int a,b;
	a = 1;
	b = 1;
	while(lsta || lstb)
	{
		if(lsta == NULL)
		{
			printf("|         |				|%9d|",lstb->content);
			if(lsta == NULL && a)
			{
				printf(" --------- ");
				a = 0;
			}
		}
		else if(lstb == NULL)
		{
			printf("|%9d|",lsta->content);
			if(lstb == NULL && b)
			{
				printf("      			 ---------");
				b = 0;
			}
		}
		else
			printf("|%9d|				|%9d|",lsta->content,lstb->content);
		if(lsta)
			lsta = lsta->next;
		if(lstb)
			lstb = lstb->next;
		printf("\n");
	}
	if(a)
		printf(" --------- \n");
	if(b)
		printf("			         ---------\n");
	
}