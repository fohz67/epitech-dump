##
## EPITECH PROJECT, 2022
## B-MAT-100-TLS-1-1-103cipher-samy.nasset
## File description:
## Makefile
##

SRC	=			./src/bisection.c \
				./src/dispatch.c \
				./src/init.c \
				./src/library.c \
				./src/newton.c \
				./src/rigor.c \
				./src/secant.c \
				./main.c

OBJ		=		$(SRC:.c=.o)

NAME	=		105torus

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
