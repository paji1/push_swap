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

int handle(int ac, char **av, t_list **lst);


#endif