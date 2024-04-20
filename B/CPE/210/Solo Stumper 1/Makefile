##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =		./main.c \
		./functions.c

OBJ =		$(SRC:.c=.o)

NAME = 		clean_str

CFLAGS = 	-W -Wall -Wextra

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
