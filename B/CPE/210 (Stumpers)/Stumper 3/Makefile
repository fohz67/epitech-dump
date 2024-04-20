##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =			./src/main.c \
			./src/error.c \
			./src/buffer.c \
			./src/sandpile.c \
			./src/is_unstable.c \
			./src/create_grid_nb.c

OBJ =			$(SRC:.c=.o)

NAME = 			sandpile

CFLAGS = 		-I ./include -W -Wall -Wextra

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all
