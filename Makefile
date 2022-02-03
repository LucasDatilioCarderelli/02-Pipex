# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 20:14:36 by ldatilio          #+#    #+#              #
#    Updated: 2022/02/01 09:46:03 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=leak

DIR		=	./src/
DIR2	=	./utils/

SRC 	=	$(addprefix $(DIR), \
				pipex.c)

UTILS 	=	$(addprefix $(DIR2),)

OBJS 	=	${SRC:.c=.o} ${UTILS:.c=.o}

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all, clean, fclean, re, bonus, rebonus