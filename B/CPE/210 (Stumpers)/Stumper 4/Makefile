##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LIB =			./lib/my_tokarray.c \
			./lib/my_strlen.c \
			./lib/my_free.c

SRC =			./src/main.c \
			./src/error.c \
			./src/buffer.c \
			./src/create_content.c \
			./src/create_grid.c \
			./src/print_grid.c

OBJ =			$(LIB:.c=.o) \
			$(SRC:.c=.o)

NAME = 			mixword

CFLAGS = 		-I ./include -W -Wall -Wextra

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
			rm -f $(OBJ)
			find . \( -name "#*#" -o -name "*~" \) -delete

fclean:			clean
			rm -f $(NAME)

re:			fclean all
