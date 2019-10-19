/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:43:34 by kchong            #+#    #+#             */
/*   Updated: 2019/02/15 16:22:03 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapi;

	i = -1;
	mapi = (char *)(malloc(sizeof(*mapi) * ft_strlen(s) + 1));
	if (!mapi)
		return (NULL);
	while (++i < (int)ft_strlen(s))
		mapi[i] = (*f)(i, s[i]);
	mapi[i] = '\0';
	return (mapi);
}
