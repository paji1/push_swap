/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:39:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/07 00:07:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pushSwap.h"


t_hash *ft_new_hash(int content,int t)
{
	t_hash *new  = malloc(sizeof(t_hash));
	new->key = t;
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
	static int t;

	len = 0;
	if (!(*lst))
		t = 0;
	while(a)
	{
		add_hash(lst , ft_new_hash(a->content,t++));
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
void sort_hash(t_hash **sorted_hash,t_list *stack_a,int len)
{
	static int r;
	t_list *a;
	if (!stack_a)
		return ;
	int i = stack_a->content;
	
	if(!(*sorted_hash))
		r = len-1;
	while(r >= 0)
	{
		a = stack_a;
		while (a)
		{
			if(i < a->content && find_key(a->content,*sorted_hash) == -1)
				i = a->content;
			a = a->next;
		}
		add_hash(sorted_hash , ft_new_hash(i,r--));
		i = find_MIN(stack_a).lst->content;
	}
		
}

