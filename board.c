/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:23:19 by kchong            #+#    #+#             */
/*   Updated: 2019/07/02 16:32:14 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**new_board(int sq)
{
	int	**board;
	int	c;
	int	i;

	c = -1;
	if (!(board = (int **)malloc(sizeof(int *) * sq)))
		return (NULL);
	while (++c < sq)
	{
		if (!(board[c] = (int *)malloc(sizeof(int) * sq)))
			return (NULL);
		i = -1;
		while (++i < sq)
			board[c][i] = '.';
	}
	return (board);
}

int		position(int **board, t_tet *t, int sq, int alpha)
{
	int	x;
	int	i;
	int	j;

	i = t->r - t->tet[0];
	j = t->c - t->tet[1];
	x = -2;
	while ((x += 2) < 7)
	{
		t->tet[x] += i;
		t->tet[x + 1] += j;
	}
	x = -2;
	while ((x += 2) < 7)
	{
		if (t->tet[x] < 0 || t->tet[x] >= sq || t->tet[x + 1] < 0 || \
				t->tet[x + 1] >= sq || board[t->tet[x]][t->tet[x + 1]] != '.')
			return (0);
	}
	x = -2;
	while ((x += 2) < 7)
		board[t->tet[x]][t->tet[x + 1]] = alpha;
	return (1);
}

int		cleaner(int x, int **board, int sq, int *s)
{
	if (x == 0)
	{
		while (x < sq)
			free(board[x++]);
		free(board);
	}
	else if (x == 1)
	{
		x = -2;
		while ((x += 2) < 7)
			board[s[x]][s[x + 1]] = '.';
	}
	return (0);
}

int		solve(int **board, t_tet *t, int sq, int x)
{
	while (position(board, t, sq, x + 'A') == 0)
	{
		if ((t->c++) >= sq)
		{
			t->c = 0;
			if ((t->r++) >= sq)
			{
				t->r = 0;
				if (x == 0)
					return (-1);
				return (0);
			}
		}
	}
	return (1);
}

int		board(t_tet *tets, int tetcount, int sq, int x)
{
	int	**board;
	int	ret;

	while (sq * sq / (tetcount * 4) < 1)
		sq++;
	if (!(board = new_board(sq)))
		return (-1);
	while (++x < tetcount)
	{
		ret = solve(board, &tets[x], sq, x);
		if (ret == 0)
		{
			cleaner(1, board, 0, tets[--x].tet);
			tets[x--].c++;
		}
		if (ret == -1)
		{
			cleaner(0, board, sq++, NULL);
			if (!(board = new_board(sq)))
				return (-1);
			x = -1;
		}
	}
	printboard(board, sq);
	return (1 + cleaner(0, board, sq, NULL));
}
