##
## EPITECH PROJECT, 2023
## corewar
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

NAME = corewar

SRC	=	main.c \
		help.c \
		op.c \
		error.c \

OBJ =			$(SRC:.c=.o) \

CFLAGS = -W -Wall -Wextra -I../include

LDFLAGS = -L../lib -lmy

MAKE = make --no-print-directory

FILE = $(shell echo $(SRC) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find -type f -name '*.o' | wc -l | sed -e 's/ //g')
CURRENT_FILE = $(shell echo '$$(( $(CURRENT_FILES) + 1 ))')

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -en "$(CLEARL)$(BLUE)[$(YELLOW)building$(BLUE)]$(WHITE) "
	@echo -en "$(BLUE)$(notdir $@) "
	@echo -e "$(GREEN)($(CURRENT_FILE)/$(FILE))$(WHITE)$(BEGINL)"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(CLEARL)$(GREEN)Compiled $(YELLOW)$(NAME)$(WHITE)$(COL_END)"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "$(CLEARL)$(YELLOW)Cleaner $(RED)clean success$(COL_END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

debug: CFLAGS += -g3
debug: re
