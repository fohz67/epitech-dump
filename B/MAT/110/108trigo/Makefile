##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LIB =			./lib/my_abs.c \
				./lib/my_free.c \
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

SRC =			./src/build.c \
				./src/cal.c \
				./src/display.c \
				./src/errors.c \
				./src/main.c \
				./src/matrix.c \
				./src/process.c \
				./src/trigo.c \
				./src/values.c

OBJ =			$(LIB:.c=.o) \
				$(SRC:.c=.o)

NAME = 			108trigo

CFLAGS = 		-I ./include -W -Wall -Wextra

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
