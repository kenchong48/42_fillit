/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:26:54 by kchong            #+#    #+#             */
/*   Updated: 2019/02/15 16:20:52 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = -1;
	map = (char *)(malloc(sizeof(*map) * ft_strlen(s) + 1));
	if (!map)
		return (NULL);
	while (++i < (int)ft_strlen(s))
		map[i] = (*f)(s[i]);
	map[i] = '\0';
	return (map);
}
