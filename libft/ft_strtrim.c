/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:52:56 by kchong            #+#    #+#             */
/*   Updated: 2019/02/21 20:10:37 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	first;
	size_t	last;
	char	*trim;

	first = 0;
	last = ft_strlen(s) - 1;
	while (ft_isspace(s[first]))
		first++;
	if (first >= last)
		return (ft_strnew(0));
	while (ft_isspace(s[last]))
		last--;
	if (!(trim = ft_strsub(s, first, last - first + 1)))
		return (NULL);
	return (trim);
}
