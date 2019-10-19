/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:18:02 by kchong            #+#    #+#             */
/*   Updated: 2019/07/02 16:32:24 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_tet
{
	char		*tetbuff;
	int			tet[8];
	int			r;
	int			c;
}				t_tet;

int				verifile(char *file, t_tet *tets, int n);
void			convertet(char *str, int *coordinates);
int				verimino(char *tet, int part);
void			printboard(int **board, int square);
int				board(t_tet *tets, int tetcount, int sq, int x);
int				solve(int **board, t_tet *t, int sq, int x);
int				cleaner(int x, int **board, int sq, int *s);
int				position(int **board, t_tet *t, int sq, int alpha);
int				**new_board(int sq);

#endif
