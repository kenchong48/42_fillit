/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:50:48 by kchong            #+#    #+#             */
/*   Updated: 2019/02/21 20:09:06 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	a;
	size_t	z;
	int		i;

	a = 0;
	i = -1;
	if (!(split = (char **)(malloc(sizeof(char *) * (ft_wcc(s, c) + 1)))))
		return (NULL);
	while (++i < (int)ft_wcc(s, c))
	{
		while (s[a] == c && s[a] != '\0')
			a++;
		z = a + 1;
		while (s[z] != c && s[z] != '\0')
			z++;
		if ((s[z] == c && s[z - 1] != c) || (s[z] == '\0' && s[z - 1] != c))
		{
			split[i] = ft_strsub(s, a, z - a);
			a = z;
		}
	}
	split[i] = 0;
	return (split);
}
