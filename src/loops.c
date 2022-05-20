/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 05:22:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 21:17:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int	lood_a_front(t_list *stack_a, int *i, int content, t_MIN_MAX mn)
{
	int	t;
	int	size;

	t = 0;
	size = stack_a->size;
	while (stack_a->next && *i <= size / 2)
	{
		if (i_mm(mn.min.num, mn.max.num, stack_a->content, \
			stack_a->next->content))
		{
			*i += 1;
			t = *i;
			stack_a = stack_a->next;
			continue ;
		}
		if (is_bettwen(stack_a->content, content, stack_a->next->content))
		{
			*i += 1;
			break ;
		}
		*i += 1;
		stack_a = stack_a->next;
	}
	return (t);
}

int	lood_a_back(t_list *stack_a, int *t, int content, t_MIN_MAX mn)
{
	t_list	*last;
	int		b;
	int		size;

	last = stack_a->prev;
	b = -1;
	size = stack_a->size;
	while (last->content != stack_a->content && - b <= size / 2)
	{
		if (i_mm(mn.min.num, mn.max.num, last->content, last->prev->content))
		{
			*t = b;
			b--;
			last = last->prev;
			continue ;
		}
		if (is_bettwen(last->content, content, last->prev->content))
			break ;
		b--;
		last = last->prev;
	}
	return (b);
}

void	loop_front(int *tmp, int *best, t_list *stack_a, t_list *stack_b)
{
	int	size_b;
	int	i;

	i = -1;
	best[0] = 0;
	size_b = stack_b->size;
	while (stack_b && ++i <= size_b)
	{
		tmp[1] = get_a(stack_a, stack_b->content);
		tmp[0] = i;
		if (!i)
			best[1] = tmp[1];
		best_move(tmp, best);
		stack_b = stack_b->next;
	}
}

void	loop_back(int *tmp, int *best, t_list *stack_a, t_list *stack_b)
{
	int		j;
	int		size_b;
	t_list	*bot_b;

	j = -1;
	size_b = stack_b->size;
	bot_b = stack_b->prev;
	while (bot_b->content != stack_b->content && - j <= size_b / 2)
	{
		tmp[1] = get_a(stack_a, bot_b->content);
		tmp[0] = j--;
		best_move(tmp, best);
		bot_b = bot_b->prev;
	}
}

int	parse_loop(t_inis i, t_list **lst)
{
	char	*s;

	while (--i.j >= 0)
	{
		i.t = -1;
		i.num = ft_atoi(i.s[i.j]);
		s = ft_itoa(i.num);
		if (ft_strcmp(s, i.s[i.j]))
			return (free(s), free_list(i.s, i.j), free(i.s), 1);
		if (is_in(i.num))
			return (free_list(i.s, i.j), free(i.s), 1);
		while (i.s[i.j][++i.t])
			if (check_char(i.s[i.j][i.t], i.t, i.s[i.j][(i.t) + 1]))
				return (free_list(i.s, i.j), free(i.s), 1);
		push(lst, ft_lstnew(i.num));
		free(i.s[i.j]);
		free(s);
	}
	return (0);
}
