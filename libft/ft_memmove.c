/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:37:07 by kchong            #+#    #+#             */
/*   Updated: 2019/02/15 16:17:55 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*(char *)(dst + len) = *(char *)(src + len);
	else
		while (++i < (int)len)
			*(char *)(dst + i) = *(char *)(src + i);
	return (dst);
}
