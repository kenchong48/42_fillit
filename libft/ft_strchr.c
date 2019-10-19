/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:42:12 by kchong            #+#    #+#             */
/*   Updated: 2019/03/27 08:29:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		if (*s == c)
			return ((char*)s);
		else
		{
			i--;
			s++;
		}
	}
	return (NULL);
}
