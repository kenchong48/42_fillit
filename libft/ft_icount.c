/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_icount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:07:29 by kchong            #+#    #+#             */
/*   Updated: 2019/04/10 09:24:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** finds how many digits in an integer ex: 4 in 1337
*/

size_t	ft_icount(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		count = 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (++count);
}
