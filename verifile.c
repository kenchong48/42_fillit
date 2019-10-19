/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:08:47 by kchong            #+#    #+#             */
/*   Updated: 2019/07/02 16:32:05 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verimino(char *tet, int part)
{
	int	connect;
	int	i;

	connect = 0;
	i = 0;
	if (ft_ccount(tet, '#', 0) == 4 && ft_ccount(tet, '.', 0) == 12 && \
		tet[4] == '\n' && tet[9] == '\n' && tet[14] == '\n' && tet[19] == '\n')
	{
		while (++part <= 4)
		{
			i = ft_ccount(tet, '#', part);
			if (tet[i] == tet[i + 1])
				connect++;
			if (i > 0 && tet[i] == tet[i - 1])
				connect++;
			if (i < 14 && tet[i] == tet[i + 5])
				connect++;
			if (i > 4 && tet[i] == tet[i - 5])
				connect++;
		}
		if (connect == 6 || connect == 8)
			return (1);
	}
	return (0);
}

void	convertet(char *str, int *coordinates)
{
	int	i;
	int	part;
	int	len;

	part = 0;
	len = 0;
	while (++part <= 4)
	{
		i = ft_ccount(str, '#', part);
		if (i < 4)
			coordinates[len] = 0;
		else if (i < 9)
			coordinates[len] = 1;
		else if (i < 14)
			coordinates[len] = 2;
		else if (i < 19)
			coordinates[len] = 3;
		coordinates[len + 1] = i % 5;
		len += 2;
	}
}

int		verifile(char *file, t_tet *tets, int n)
{
	int	start;
	int	len;
	int	tetcount;

	tetcount = 0;
	start = 0;
	while (n - tetcount > 0 && tetcount < 26)
	{
		len = ft_ccount(file, '\n', 5 * (tetcount + 1)) - start;
		if (len < 0)
			len = ft_strlen(file) - start;
		n = n - len;
		tets[tetcount].tetbuff = ft_strsub(file, start, len);
		start = start + len + 1;
		if (verimino(tets[tetcount].tetbuff, 0) == 0)
			return (-1);
		convertet(tets[tetcount].tetbuff, tets[tetcount].tet);
		tets[tetcount].r = 0;
		tets[tetcount].c = 0;
		tetcount++;
	}
	return (tetcount);
}
