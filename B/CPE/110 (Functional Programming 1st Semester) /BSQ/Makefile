##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_LIB = 	./lib/my_putstr.c \
		./lib/my_putchar.c \
		./lib/my_strlen.c \
		./lib/my_strcmp.c \
		./lib/my_putlong.c \
		./lib/my_strcat.c \
		./lib/my_strcpy.c \
		./lib/my_nbrlen.c \
		./lib/my_str_to_word_array.c \
		./lib/my_getnbr.c \
		./lib/my_calstr.c \
		./lib/my_strdup.c

SRC_BASIC =	./src/manage_file.c \
		./src/algorithm.c \
		./src/algorithm_nobstacle.c \
		./src/formating.c \
		./src/squaring.c \
		./src/handling.c \
		./src/generate.c \
		./main.c


OBJ =		$(SRC_LIB:.c=.o) \
		$(SRC_BASIC:.c=.o)

NAME = 		bsq

CFLAGS = -W -Wall -Wextra

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

z:		fclean
		clear
