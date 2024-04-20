##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[0;37m
BLUE = \033[1;34m
YELLOW = \033[1;33m
BEGINL = \033[A
CLEARL = \033[2K
COL_END  = \033[0m
CLEAR_COL = \033[2K\033[A

NAME = 42sh

SRC =   ./src/booleans.c \
        ./src/booleans2.c \
        ./src/engine.c \
        ./src/error.c \
        ./src/main.c \
        ./src/segfault.c \
        ./lib/my_abs.c \
        ./lib/my_free.c \
        ./lib/my_getfloat.c \
        ./lib/my_getnbr.c \
        ./lib/my_getsize_array.c \
        ./lib/my_issep.c \
        ./lib/my_itoa.c \
        ./lib/my_lenword.c \
        ./lib/my_nbline.c \
        ./lib/my_nbrlen.c \
        ./lib/my_nbword.c \
        ./lib/my_pow.c \
        ./lib/my_putarray.c \
        ./lib/my_putchar.c \
        ./lib/my_putlong.c \
        ./lib/my_putnbr.c \
        ./lib/my_putstr.c \
        ./lib/my_skipsep.c \
        ./lib/my_str_to_word_array.c \
        ./lib/my_strcat.c \
        ./lib/my_strcmp.c \
        ./lib/my_strcpy.c \
        ./lib/my_strdup.c \
        ./lib/my_strlen.c \
        ./lib/my_swap.c \
        ./lib/my_strtok.c \
        ./lib/my_tokarray.c \
        ./lib/my_tokarray_duo.c \
        ./lib/my_word_array_to_str.c \
        ./src/controllers/pipes.c \
        ./src/controllers/output_redirect.c \
        ./src/controllers/separators.c \
        ./src/command/artificial.c \
        ./src/command/real.c \
        ./src/command/verify.c \
        ./src/environment/environment.c \
        ./src/environment/paths.c \
        ./src/command/all/cd.c \
        ./src/command/all/env.c \
        ./src/command/all/exit.c \
        ./src/command/all/setenv.c \
        ./src/command/all/unsetenv.c \
        ./src/command/all/echo.c \
        ./src/controllers/and_separators.c \
        ./src/config/scripting.c \
        ./src/config/get_theme.c \
        ./src/config/get_alias.c \
        ./src/prompt/prompt.c \
        ./src/config/check_structure.c \
        ./src/command/all/inibitors.c \
        ./src/signals/signal.c \
        ./src/controllers/or_separators.c \
        ./src/controllers/double_input_redirect.c \
        ./src/controllers/input_redirect.c \

OBJ =	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -I./include

MAKE = make --no-print-directory

FILE = $(shell echo $(SRC) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find src -type f -name '*.o'|wc -l|sed -e 's/ //g')
CURRENT_FILE = $(shell echo '$$(( $(CURRENT_FILES) + 1 ))')

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -en "$(CLEARL)$(BLUE)[$(YELLOW)building$(BLUE)]$(WHITE) "
	@echo -en "$(BLUE)$(notdir $@) "
	@echo -e "$(GREEN)($(CURRENT_FILE)/$(FILE))$(WHITE)$(BEGINL)"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo -e "$(CLEARL)$(YELLOW)$(NAME) $(GREEN)✔$(WHITE)$(COL_END)"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "$(RED)clean success$(COL_END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
