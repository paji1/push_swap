/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:15:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/02/02 14:04:46 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sstrjoin(char *s1, char *s2)
{
	char	*p;
	size_t	lens;
	size_t	lenf;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s2);
	lenf = ft_strlen(s1);
	p = (char *)malloc(lenf + lens + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, lenf + 1);
	ft_strlcpy(p + lenf, s2, lenf + lens + 1);
	if (!*p)
		return (free(p), NULL);
	if (*s1)
		free(s1);
	return (p);
}

int	ft_getindex(const char *p, int c)
{
	int			i;

	i = 0;
	while (p[i] != (char )c && p[i])
		i++;
	if (!p[i])
		return (-1);
	return (i);
}
