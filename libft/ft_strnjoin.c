/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:43:26 by kchong            #+#    #+#             */
/*   Updated: 2019/05/21 13:45:56 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*join;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL)
		k = 0;
	else
		k = ft_strlen(s1);
	if (!(join = ft_strnew(k + len)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < k)
		join[i] = s1[i];
	while (++j < (int)len)
		join[i++] = s2[j];
	return (join);
}
