/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:38:49 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 21:04:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../gnl/get_next_line.h"
# include "../linked_list/include/linked_list.h"
# include "../libft/include/libft.h"

typedef struct inis
{
	int			num;
	int			j;
	int			t;
	char		**s;
}t_inis;
typedef struct s_MAX
{
	int		index;
	t_list	*lst;
	int		num;
}t_MAX;
typedef struct s_MIN
{
	int		index;
	t_list	*lst;
	int		num;
}t_MIN;
typedef struct MIN_MAX
{
	t_MIN	min;
	t_MAX	max;
}t_MIN_MAX;
typedef struct s_tab
{
	int	i;
	int	*tab;
	int	*is;
}t_tab;

int		handle(int ac, char **av, t_list **lst);
int		smart_rotate(t_list **stack_a, int condition, int i);
int		min_in_top(t_list **stack_a);
void	min_toposition(t_list **stack_a, int count);
void	print_stack(t_list *lst, t_list *lstb);
t_tab	*len_lis(t_tab *ss);
int		push_nlis(t_list **stack_a, t_list **stack_b, int size_a);
int		*lis_elem(t_tab *ss);
t_tab	*to_table(t_list *stack, int size);
t_MIN	find_min(t_list *lst);
t_MAX	find_max(t_list *lst);
int		find_position(int element, t_list *stack);
int		is_bettwen(int first, int num, int second);
int		i_mm(int min, int max, int first, int second);
int		get_a(t_list *stack, int content);
int		calculemoves(int *tmp);
void	best_move(int *tmp, int *best);
int		*push_back(t_list *stack_a, t_list *stack_b);
int		min_in_top_pr(t_list **stack_a);
int		smart_rotate_pr(t_list **stack_a, int condition, int i);
void	is_rbrrb(int *tmp, t_list **stack_b);
void	is_rarra(int *tmp, t_list **stack_a);
void	is_rrr(int *tmp, t_list **stack_b, t_list **stack_a);
void	is_rr(int *tmp, t_list **stack_b, t_list **stack_a);
int		parse_loop(t_inis i, t_list **lst);
int		lood_a_front(t_list *stack_a, int *i, int content, t_MIN_MAX mn);
int		lood_a_back(t_list *stack_a, int *t, int content, t_MIN_MAX mn);
void	loop_back(int *tmp, int *best, t_list *stack_a, t_list *stack_b);
void	loop_front(int *tmp, int *best, t_list *stack_a, t_list *stack_b);
int		search_bt(t_list **stack, int *nlist, int len);
int		is_empty(char *s);
int		is_in(unsigned int num);
int		check_char(char c, int i, char d);
void	free_list(char **s, int i);

#endif