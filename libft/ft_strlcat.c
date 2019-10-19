/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:55:55 by kchong            #+#    #+#             */
/*   Updated: 2019/02/21 17:11:37 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = ft_strlen(dst);
	if (dstsize < i + 1)
		return (ft_strlen(src) + dstsize);
	else if (dstsize >= i + 1)
	{
		while (i < dstsize - 1 && *src)
			dst[i++] = *src++;
		dst[i] = '\0';
	}
	return (i + ft_strlen(src));
}
