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
}t_MAX;
typedef struct s_MIN
{
	int		index;
	t_list	*lst;
}t_MIN;
typedef struct s_hash
{
	int key;
	int content;
	struct s_hash *next;
} t_hash;
t_hash *ft_new_hash(int content,int t);
void add_hash(t_hash **lst,t_hash *new);
int inis_hash(t_hash **lst,t_list *a);
int find_key(int content, t_hash *lst);
void sort_hash(t_hash **sorted_hash,t_list *stack_a,int len);

int 	handle(int ac, char **av, t_list **lst);
void	print_stack(t_list *lst, t_list *lstb);
t_MIN	find_MIN(t_list *lst);
t_MAX	find_MAX(t_list *lst);



#endif