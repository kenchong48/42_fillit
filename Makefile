# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchong <kchong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 13:02:40 by kchong            #+#    #+#              #
#    Updated: 2019/07/08 14:22:03 by kchong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		verifile.c \
		board.c \

OBJ = $(patsubst %.c,%.o,$(SRCS))

$(NAME):
	make -C libft
	gcc $(FLAGS) -c $(SRCS)
	gcc -o $(NAME) $(OBJ) libft/libft.a

all: $(NAME)

.PHONY: clean fclean re

clean:
	make -C libft clean
	rm -f libft.a
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
