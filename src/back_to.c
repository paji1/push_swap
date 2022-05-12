/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:19:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/12 02:54:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
int calculemoves(int *tmp)
{
	int moves;

	moves = 0;
	if (tmp[0] > 0 && tmp[1] > 0)
	{
		if (tmp[0] >= tmp[1])
			moves = tmp[0];
		else
			moves = tmp[1];
	}
	else if (tmp[0] < 0 && tmp[1] < 0)
	{
		if (tmp[0] >= tmp[1])
			moves = -tmp[1];
		else
			moves = -tmp[0];
	}
	else
	{
		if (tmp[0] < tmp[1])
			moves = tmp[1] - tmp[0]; 
		else
			moves = tmp[0] - tmp[1];
	}
	return moves;
}
void best_move(int *tmp, int *best)
{
	if(calculemoves(best) > calculemoves(tmp))
		ft_memcpy(best,tmp,8);
}

int	*push_back(t_list *stack_a,t_list *stack_b)
{
	t_list *head_b;
	t_list *bot_b;
	int i;
	int j;
	int size;
	int *best;
	int tmp[2];

	i = -1;
	j = -1;
	best = (int *)malloc(sizeof(int) * 4);
	size = stack_b->size;
	head_b = stack_b;
	bot_b = stack_b->prev;
	best[0] = 0;
	
	while (head_b && ++i <= size)
	{
		tmp[1] = get_a(stack_a,head_b->content);
		tmp[0] = i;
		if (!i)
			best[1] = tmp[1];
		best_move(tmp, best);
		head_b = head_b->next;
	}
	while(bot_b->content != stack_b->content && -j <= size / 2)
	{
		tmp[1] = get_a(stack_a,bot_b->content);
		tmp[0] = j--;
		best_move(tmp, best);
		bot_b = bot_b->prev;
	}
	return best;
}


int is_bettwen(int first, int num, int second)
{
	if (first < num && num  < second)
		return 1;
	else if (first > num && num > second)
		return 1; 
	return 0;
}
int i_MM(int min ,int max, int first, int second)
{
	// is bettwen max and min
	if (first == min)
	{
		if (second == max)
			return 1;
	}
	else if (first == max)
	{
		if (second == min)
			return 1;
	}
	return 0;
}
typedef struct s_head_tail 
{
	t_list *head;
	t_list *tail;
}t_head_tail;

typedef struct MIN_MAX 
{
	t_MIN min;
	t_MAX max;
}t_MIN_MAX;


int	get_a(t_list *stack, int content)
{
	int i;
	int j;
	int t;
	int size;
	t_list *stack_a;
	t_list *last;
	t_MAX max; 
	t_MIN min; 
	
	i = 0;
	j = -1;
	t = 0;
	stack_a = stack;
	last = stack->prev;
	size = stack_a->size;
	
	max = find_MAX(stack_a);
	min = find_MIN(stack_a);
		
	
	if(is_bettwen(stack_a->content, content, stack_a->prev->content))
		if (!i_MM(min.num, max.num, stack_a->content, stack_a->prev->content))
			return 0;
	while(stack_a->next && i <= size / 2)
	{
		if (i_MM(min.num, max.num, stack_a->content, stack_a->next->content))
		{
			i++;
			t = i;
			stack_a = stack_a->next;
			continue;
		}
		if(is_bettwen(stack_a->content, content, stack_a->next->content))
		{
				i++;
				break;
		}
		i++;
		stack_a = stack_a->next;
	}
	while(last->content != stack->content && -j <= size / 2)
	{
		if (i_MM(min.num, max.num, last->content, last->prev->content))
		{
			t = j;
			j--;
			last = last->prev;
			continue;
		}
		if(is_bettwen(last->content, content, last->prev->content))
				break;
		j--;
		last = last->prev;
	}
	// printf("j = %d  | i = %d\n",j, i);
	if (i > size / 2 && -j > size / 2)
		return t;
	if (i < -j)
		return i;
	else
		return j;
	return 0;
}