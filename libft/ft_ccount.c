/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:38:18 by kchong            #+#    #+#             */
/*   Updated: 2019/05/07 14:42:54 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns: index position of nth c in str
** if n is 0, returns number of c in str
** -1 if error or not found
*/

int	ft_ccount(char const *str, char c, size_t n)
{
	size_t i;
	size_t j;
	size_t x;

	i = 0;
	j = n;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			x++;
			j--;
			if (j == 0)
				return (i);
		}
		i++;
	}
	if (n == 0)
		return (x);
	return (-1);
}
