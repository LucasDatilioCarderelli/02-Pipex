# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 20:14:36 by ldatilio          #+#    #+#              #
#    Updated: 2022/02/13 21:14:59 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
NAME_BONUS	=	pipex_bonus

CC			=	gcc -g

CFLAGS		=	-Wall -Werror -Wextra -fsanitize=leak

DIR_SRC		=	./src/
DIR_UTILS	=	./utils/
DIR_BONUS	=	./bonus/

SRC 		=	$(addprefix $(DIR_SRC),		\
				cmd_parser.c 	\
				errors.c 		\
				pipex.c 		\
				)

BONUS 		=	$(addprefix $(DIR_BONUS),	\
				cmd_parser.c 	\
				errors.c 		\
				pipex.c 		\
				)

UTILS 		=	$(addprefix $(DIR_UTILS),	\
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

OBJS 		=	${UTILS:.c=.o} ${SRC:.c=.o}
OBJS_BONUS	=	$(UTILS:.c=.o) ${BONUS:.c=.o}

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)
bonus:			$(NAME_BONUS)

$(NAME): 		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

clean:
				rm -f $(OBJS) $(OBJS_BONUS)

fclean:			clean
				rm -f $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY: 		all, clean, fclean, re, bonus, rebonus