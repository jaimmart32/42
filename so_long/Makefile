NAME = so_long

SRC = $(MAIN_SRC) $(SRC_GNL) $(SRC_MAP) $(SRC_GAME)

MAIN_SRC = main.c errors.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))

MAP = 	map_reader.c map_checker.c map_checker_utils.c \
		tilemap_generator.c
SRC_MAP = $(addprefix map/, $(MAP))

GAME =	game_init.c end_program.c input.c render.c \
		open_images.c player_movement.c player_final.c
SRC_GAME = $(addprefix game/, $(GAME))

OBJ = *.o
CC = gcc -g
FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -lXext -lX11 -lm

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@$(CC) $(FLAGS) -c $(SRC)

norm:
	@echo $(GRAY) ""
	@norminette $(SRC) *.h */*.h
	@echo $(NONE) ""

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean

re: fclean all
