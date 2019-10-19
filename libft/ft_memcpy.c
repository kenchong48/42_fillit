/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:17:09 by kchong            #+#    #+#             */
/*   Updated: 2019/02/13 21:19:44 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*t;

	t = dst;
	while (n != 0)
	{
		*(char *)dst = *(char *)src;
		src++;
		dst++;
		n--;
	}
	return ((void *)t);
}
