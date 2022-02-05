# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 20:14:36 by ldatilio          #+#    #+#              #
#    Updated: 2022/02/04 22:15:38 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra #-fsanitize=leak

DIR		=	./src/
DIR2	=	./utils/

SRC 	=	$(addprefix $(DIR), \
				args_parser.c 	\
				pipex.c 		\
			)

UTILS 	=	$(addprefix $(DIR2),\
				ft_bzero.c 		\
				ft_calloc.c 	\
				ft_memcpy.c 	\
				ft_memset.c 	\
				ft_split.c 		\
				ft_strdup.c 	\
				ft_strjoin.c 	\
				ft_strlcpy.c 	\
				ft_strlen.c 	\
				ft_substr.c 	\
			)

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