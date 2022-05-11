#ifndef PUSHSWAP_H
#define PUSHSWAP_H


typedef struct inis
{
	int			num;
	int			j;
	int			t;
	char		**s;
	
}t_inis;


# include "../gnl/get_next_line.h"
# include "../linked_list/include/linked_list.h"
# include "../libft/include/libft.h"
# include <stdio.h>

typedef struct s_MAX
{
	int		index;
	t_list	*lst;
	int num;
}t_MAX;

typedef struct s_MIN
{
	int		index;
	t_list	*lst;
	int num;
}t_MIN;

typedef struct s_hash
{
	int key;
	int content;
	struct s_hash *next;
} t_hash;

typedef struct s_tab
{
	int i;
	int *tab;
	int *is;
} t_tab;

int		find_key(int content, t_hash *lst);
int		inis_hash(t_hash **lst,t_list *a);
int 	handle(int ac, char **av, t_list **lst);
void	add_hash(t_hash **lst,t_hash *new);
void	sort_hash(t_hash **sorted_hash,t_list *stack_a,int len);
int		smart_rotate(t_list **stack_a,int condition,int i);
int		min_in_top(t_list **stack_a);
void	min_toposition(t_list **stack_a,int count);
void	print_stack(t_list *lst, t_list *lstb);
t_tab	*len_LIS(t_tab *ss);
int		push_nlis(t_list **stack_a, t_list **stack_b, int size_a);
int		*Lis_elem(t_tab *ss);
t_hash	*ft_new_hash(int content,int t);
t_tab	*to_table(t_list *stack,int size);
t_MIN	find_MIN(t_list *lst);
t_MAX	find_MAX(t_list *lst);
int		find_position(int element, t_list *stack);
int		is_bettwen(int first, int num, int second);
int		i_MM(int min ,int max, int first, int second);
int		get_a(t_list *stack, int content);
int		calculemoves(int *tmp);
void	best_move(int *tmp, int *best);
int		*push_back(t_list *stack_a,t_list *stack_b);
int		min_in_top_pr(t_list **stack_a);
int		smart_rotate_pr(t_list **stack_a,int condition,int i);
void	is_rbrrb(int *tmp,t_list **stack_b);
void	is_rarra(int *tmp,t_list **stack_a);
void	is_rrr(int *tmp,t_list **stack_b, t_list **stack_a);
void	is_rr(int *tmp,t_list **stack_b, t_list **stack_a);
#endif