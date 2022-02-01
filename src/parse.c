/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:44:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:48 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushSwap.h"

int handle(int ac, char **av, t_list **lst)
{
	int		j;
	int		t;
	char	**s;
	
	if(ac <= 1)
		return 0; 
	while (--ac > 0)
	{
		s = ft_split(av[ac],' ');
		j = countwords(av[ac],' ');
		while(--j >= 0)
		{
			t = -1;
			while (s[j][++t])
				if(!ft_strchr("0123456789-+",s[j][t]))
					return (free(s[j]), free(s), 0);
			push(lst, ft_lstnew(ft_atoi(s[j])));
			free(s[j]);
		}
		free(s);
	}
	return 1;
}