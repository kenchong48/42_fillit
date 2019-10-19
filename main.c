/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 08:56:21 by kchong            #+#    #+#             */
/*   Updated: 2019/07/08 13:57:23 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printboard(int **board, int square)
{
	int		r;
	int		c;

	r = -1;
	while (++r < square)
	{
		c = -1;
		while (++c < square)
			ft_putchar(board[r][c]);
		ft_putchar(10);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*source;
	int		rret;
	t_tet	tets[26];
	int		tetcount;

	rret = 0;
	if (argc != 2)
	{
		write(1, "fillit tetriminos_file\n", 23);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	source = (char *)malloc(sizeof(char) * 546);
	ft_bzero(source, 546);
	rret = read(fd, source, 546);
	if (((rret - 20) % 21) != 0 || \
		(tetcount = verifile(source, tets, rret)) < 1 \
		|| board(tets, tetcount, 1, -1) < 0)
		write(1, "error\n", 6);
	ft_strclrdel(&source);
	close(fd);
	return (0);
}
