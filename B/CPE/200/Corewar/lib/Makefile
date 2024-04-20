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

LIB =		my_abs.c \
			my_free.c \
			my_getfloat.c \
			my_getnbr.c \
			my_getsize_array.c \
			my_isnbr.c \
			my_issep.c \
			my_itoa.c \
			my_lenword.c \
			my_nbline.c \
			my_nbrlen.c \
			my_nbword.c \
			my_pow.c \
			my_putarray.c \
			my_putchar.c \
			my_putlong.c \
			my_putnbr.c \
			my_putstr.c \
			my_skipsep.c \
			my_str_to_word_array.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_strdup.c \
			my_strlen.c \
			my_strtok.c \
			my_swap.c \
			my_tokarray.c \
			my_word_array_to_str.c \
			my_memset.c \
			my_str_lowercase.c \
			my_str_cleaner.c \
			my_atoi.c \
			int_to_short.c \
			modif_itoa.c \
			my_evil_str.c

NAME = libmy.a

OBJ =	$(LIB:.c=.o) \

CFLAGS = -W -Wall -Wextra -I../include

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
	@ar rc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "$(CLEARL)$(GREEN)Compiled $(YELLOW)$(NAME)$(WHITE)$(COL_END)"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "$(CLEARL)$(YELLOW)Cleaner $(RED)clean success$(COL_END)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
