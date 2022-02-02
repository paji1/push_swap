/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:44:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/02 19:08:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

static void free_list(char **s,int i)
{
	while (i)
		free(s[i--]);
	free(s[i]);
}

static int is_spaces(char *s)
{
	while(*s)
	{
		if(*s != ' ')
			return 0;
		s++;
	}
	return 1;
}

static int is_in(int num)
{
	static int	tab[4294967295];
	if(tab[(unsigned int)num] == -1)
		return 1;
	tab[(unsigned int)num] = -1;
	return 0;
}

int handle(int ac, char **av, t_list **lst)
{
	t_inis i;
	
	if(ac <= 1)
		return (0); 
	while (--ac > 0)
	{
		i.s = ft_split(av[ac],' ');
		i.j = countwords(av[ac],' ');
		if (is_spaces(av[ac]))
				return (free_list(i.s,i.j), free(i.s), 0);
		while(--i.j >= 0)
		{
			i.t = -1;
			i.num = ft_atoi(i.s[i.j]);
			if (is_in(i.num))
				return (free_list(i.s,i.j), free(i.s), 0);
			while (i.s[i.j][++i.t])
				if (!ft_strchr("0123456789-+",i.s[i.j][i.t]) || \
					(ft_strchr("-+",i.s[i.j][i.t]) && i.t))
					return (free_list(i.s,i.j), free(i.s), 0);
			push(lst, ft_lstnew(i.num));
			free(i.s[i.j]);
		}
		free(i.s);
	}
	return (1);
}