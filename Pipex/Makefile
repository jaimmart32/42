# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 12:14:19 by jaimmart          #+#    #+#              #
#    Updated: 2022/12/14 14:20:09 by jaimmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf


HEADER = pipex.h

PIPEX_SRC = pipex.c childs.c error.c free.c
PIPEX_OBJ = $(PIPEX_SRC:.c=.o)

LIBFT_SRC = ft_strlen.c ft_strjoin.c ft_split.c ft_strncmp.c ft_strdup.c \
ft_strlcpy.c ft_strlcat.c ft_substr.c
LIBFT_DIR = mini_libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
LIBFT_OBJ = $(LIBFT:.c=.o)


%.o:	%.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):	$(LIBFT_OBJ) $(PIPEX_OBJ)
				@${CC} ${LIBFT_OBJ} ${PIPEX_OBJ} -o ${NAME}
				@echo "$(GREEN)$(NAME) created fella!"

all:		$(NAME)

clean:
			@$(RM) $(PIPEX_OBJ)
			@$(RM) $(LIBFT_OBJ)
			@echo "$(YELLOW)object files distroyed bro!"

fclean:	clean
			@$(RM) $(NAME)
			@echo "$(RED)all stuff is distroyed as you wished!"

re:		fclean all

.PHONY:		all clean fclean re


GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m