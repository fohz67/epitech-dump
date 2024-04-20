##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_LIB = 		./lib/itoa.c \
			./lib/my_putstr.c \
            ./lib/my_putchar.c \
            ./lib/my_strlen.c \
            ./lib/my_strcmp.c \
			./lib/my_putlong.c \
			./lib/my_strcat.c \
			./lib/my_strcpy.c \
			./lib/my_strdup.c

SRC =			./main.c \
			./file.c \
			./getters.c \
			./keys.c \
			./map.c \
			./moves.c

OBJ =			$(SRC_LIB:.c=.o) \
			$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME = 			my_sokoban

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME) -lncurses

all:			$(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

z:			fclean
			clear
