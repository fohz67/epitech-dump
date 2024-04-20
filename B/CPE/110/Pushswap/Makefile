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
			./lib/my_getnbr.c \
			./lib/my_strdup.c

SRC =			./main.c \
			./src/minimum.c \
			./src/error.c \
			./src/order.c \
			./src/create_tab.c \
			./src/display.c \
			./src/sort.c

OBJ =			$(SRC_LIB:.c=.o) \
			$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME = 			push_swap

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

z:			fclean
			clear
