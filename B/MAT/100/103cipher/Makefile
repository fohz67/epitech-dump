##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =			./main.c

OBJ =			$(SRC:.c=.o)

NAME = 			103cipher

CFLAGS = -W -Wall -Wextra

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME) -lm

all:			$(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

z:			fclean
			clear
