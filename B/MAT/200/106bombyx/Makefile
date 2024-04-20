##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =			./main.c \
				./check.c

OBJ =			$(SRC_LIB:.c=.o) \
				$(SRC:.c=.o)

NAME = 			106bombyx

CFLAGS = 		-W -Wall -Wextra

$(NAME):		$(OBJ)
				gcc $(OBJ) -o $(NAME) -lm

all:			$(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

z:				fclean
				clear
