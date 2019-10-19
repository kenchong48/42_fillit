/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:38:12 by kchong            #+#    #+#             */
/*   Updated: 2019/02/21 20:08:18 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;

	if (!(t = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(t, size + 1);
	return (t);
}
