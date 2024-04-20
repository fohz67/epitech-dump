##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_LIB = 		./lib/my_putstr.c \
				./lib/my_putchar.c \
				./lib/my_strlen.c \
				./lib/my_strcmp.c \
				./lib/my_putlong.c \
				./lib/my_strcat.c \
				./lib/my_strcpy.c \
				./lib/my_nbrlen.c \
				./lib/my_str_to_word_array.c \
				./lib/my_str_to_word_antitab_array.c \
				./lib/my_getnbr.c \
				./lib/my_calstr.c \
				./lib/my_strdup.c \
				./lib/my_abs.c \
				./lib/my_getfloat.c \
				./lib/my_itoa.c \
				./lib/my_isnum.c \
				./lib/my_pow.c

SRC =			./main.c \
				./check.c \
				./show.c \
				./intersections.c \
				./define.c

OBJ =			$(SRC_LIB:.c=.o) \
				$(SRC:.c=.o)

NAME = 			104intersection

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
