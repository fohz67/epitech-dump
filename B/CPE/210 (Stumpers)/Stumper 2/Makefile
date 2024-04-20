##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC =	src/main.c \
	src/buffer.c \
	src/manage_errors.c \
	src/load_map.c \
	src/engine.c \
	src/print.c \
	src/data.c

OBJ = $(SRC:.c=.o)

NAME = my_ginger

CFLAGS = -W -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f #*#

re:	fclean all

.PHONY: all clean fclean re
