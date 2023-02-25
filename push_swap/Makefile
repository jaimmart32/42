# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 21:10:46 by jaimmart          #+#    #+#              #
#    Updated: 2023/02/25 15:52:41 by jaimmart32       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES OF MAKEFILE
NAME = push_swap

# vpath defines a ':'separated list of directories to search for source files.
vpath %.c algos:commands:utils
SRCS =  radix.c simple.c pushs.c rev_rotate.c rotate.c swaps.c checks.c \
		error_and_free.c index.c list_utils.c stack_utils.c main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

# MAKEFILE TARGETS AND RECIPIES
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

# .PHONY target is a special target that is not associated with a file. 
# Instead, it is used to declare a list of targets that should always be 
# considered out of date and should therefore always be run, regardless of 
# whether a file with that name exists or not.
.PHONY: all clean fclean re
