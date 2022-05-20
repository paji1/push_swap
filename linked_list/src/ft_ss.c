/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:51:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/20 19:29:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_ss_rr(t_list **lsta, t_list **lstb)
{
	ft_sa_rr(lsta);
	ft_sb_rr(lstb);
}

void	ft_ss(t_list **lsta, t_list **lstb)
{
	ft_ss_rr(lsta, lstb);
	write(1, "ss\n", 3);
}
