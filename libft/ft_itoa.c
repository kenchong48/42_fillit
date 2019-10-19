/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:10:52 by kchong            #+#    #+#             */
/*   Updated: 2019/02/21 14:52:55 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		count;
	char	*a;

	count = ft_icount(n);
	if (!(a = ft_strnew((size_t)count)))
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		while (count-- > 1)
		{
			a[count] = (n % -10) * -1 + '0';
			n = n / 10;
		}
	}
	else
		while (count-- > 0)
		{
			a[count] = n % 10 + '0';
			n = n / 10;
		}
	return (a);
}
