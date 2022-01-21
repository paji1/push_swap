/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/01/21 08:38:58 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>

int handle(int ac, char **av, t_list **lst)
{
	int		j;
	int		t;
	char	**s;
	
	if(ac <= 1)
		return 0; 
	while (--ac > 0)
	{
		s = ft_split(av[ac],' ');
		j = countwords(av[ac],' ');
		while(--j >= 0)
		{
			t = -1;
			while (s[j][++t])
				if(!ft_strchr("0123456789-+",s[j][t]))
					return (free(s[j]), free(s), 0);
			push(lst, ft_lstnew(ft_atoi(s[j])));
			free(s[j]);
		}
		free(s);
	}
	return 1;
}
int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
		
	stack_a = NULL;
	stack_b = NULL;
	if(handle(ac,av,&stack_a))
		printf("%d",stack_a->prev->content);
	else
		printf("error");
	
	ft_free(&stack_a);
	// ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
	
}