/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:19:27 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/17 08:21:31 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}