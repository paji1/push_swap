/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/04 18:26:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#include <stdio.h>

typedef struct s_hash
{
	int key;
	int content;
	struct s_hash *next;
} t_hash;

t_hash *ft_new_hash(int content)
{
	static int i = 0;
	t_hash *new  = malloc(sizeof(t_hash));
	new->key = i++;
	new->content = content;
	return new;
}

void add_hash(t_hash **lst,t_hash *new)
{
	new->next = *lst;
	*lst = new;
}

int inis_hash(t_hash **lst,t_list *a)
{
	int len;

	len = 0;
	while(a)
	{
		add_hash(lst , ft_new_hash(a->content));
		a = a->next;
		++len;
	}
	return len;
}
int find_key(int content, t_hash *lst)
{
	
	while (lst)
	{
		if(lst->content == content)
			return lst->key;
		lst = lst->next;
	}
	return -1;
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// t_MIN	min;
	// t_hash *hash;
	
	
	stack_a = NULL;
	stack_b = NULL;
	if(ac <= 1)
		return 0;
	if(!handle(ac,av,&stack_a))
		return printf("error"), ft_free(&stack_a), ft_free(&stack_b), 0;
	// int len = inis_hash(&hash,stack_a);

	// printf("key = %d\n",find_key(44,hash));
	// while (hash)
	// {
	// 	printf("key = %d content = %d\n",hash->key, hash->content);
	// 	hash = hash->next;
	// }
	// printf("len = %d\n",len);
	// // min = find_MIN(stack_a);
	
	// int i = -1;
	// while (++i < 5)
	// {
	// 	ft_pb(&stack_a,&stack_b);
	// 	printf("pb\n");	
	// }
	// while(stack_a)
	// {
	// 	if(stack_a != min.lst)
	// 	{
	// 		printf("ra\n");
	// 		ft_ra(&stack_a);
	// 	}
	// 	else
	// 	{
	// 		ft_pb(&stack_a,&stack_b);
	// 		printf("pb\n");
	// 		min = find_MIN(stack_a);
	// 	}
	// }
	// t_list *temp = stack_b;
	// while (temp)
	// {
	// 	ft_pa(&stack_a,&stack_b);
	// 	temp = temp->next;
	// }

	// print_stack(stack_a,stack_b);


	// printf("%d",stack_a->prev->content);
	
	// while(stack_b)
	// {
	// 	printf(" %d ",stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	
	// return (ft_free(&stack_a),0);
	
}