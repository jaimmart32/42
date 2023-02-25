# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 21:10:46 by jaimmart          #+#    #+#              #
#    Updated: 2023/02/25 14:45:34 by jaimmart32       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

vpath %.c algos:commands:utils
SRCS =  radix.c simple.c pushs.c rev_rotate.c rotate.c swaps.c checks.c \
		error_and_free.c index.c list_utils.c stack_utils.c main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
