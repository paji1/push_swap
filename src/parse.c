/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:44:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/17 12:52:46 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"
#define ARRAY_SIZE  500

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

int is_in(unsigned int num)
{
	static unsigned char arr[ARRAY_SIZE];
	if ((((arr[(num - num%8) / 8] >> num%8 ) & 1) == 1))
		return 1;
	arr[(num - num%8) / 8] = arr[(num - num%8) / 8] | 1 << (num % 8);	
	return 0;
}

int check_char(char c,int i,char d)
{
	if (!ft_strchr("0123456789-+",c) || (ft_strchr("-+",c) && (i || !d)))
		return 1;
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
		if(!(i.s))
			return (0);
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
				if (check_char(i.s[i.j][i.t],i.t,i.s[i.j][(i.t) + 1]))
					return (free_list(i.s,i.j), free(i.s), 0);
			push(lst, ft_lstnew(i.num));
			free(i.s[i.j]);
		}
		free(i.s);
	}
	return (1);
}