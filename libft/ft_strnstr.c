/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:35:39 by kchong            #+#    #+#             */
/*   Updated: 2019/02/14 18:08:43 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (j < len && *haystack)
	{
		i = 0;
		while (i + j < len && needle[i] != '\0' && needle[i] == haystack[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		j++;
	}
	return (NULL);
}
