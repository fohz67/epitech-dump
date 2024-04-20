##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LIB =			./lib/my_abs.c \
				./lib/my_getfloat.c \
				./lib/my_getnbr.c \
				./lib/my_getsize_array.c \
				./lib/my_issep.c \
				./lib/my_itoa.c \
				./lib/my_lenword.c \
				./lib/my_nbline.c \
				./lib/my_nbrlen.c \
				./lib/my_nbword.c \
				./lib/my_pow.c \
				./lib/my_putarray.c \
				./lib/my_putchar.c \
				./lib/my_putlong.c \
				./lib/my_putnbr.c \
				./lib/my_putstr.c \
				./lib/my_skipsep.c \
				./lib/my_str_to_word_array.c \
				./lib/my_strcat.c \
				./lib/my_strcmp.c \
				./lib/my_strcpy.c \
				./lib/my_strdup.c \
				./lib/my_strlen.c \
				./lib/my_swap.c \
				./lib/my_word_array_to_str.c

SRC =			./main.c \
				./src/error.c \
				./src/construct.c \
				./src/imperfect.c \
				./src/perfect.c \
				./src/generator.c \
				./src/free.c

OBJ =			$(SRC:.c=.o) \
				$(LIB:.c=.o)

NAME = 			generator

CFLAGS = 		-I ./include -W -Wall -Wextra

$(NAME):		$(OBJ)
				gcc $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

z:				fclean
				clear

.PHONY:			all clean fclean re
