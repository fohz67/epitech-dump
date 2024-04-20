##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_BASIC =	./duck.c \
		./manage.c \
		./main.c \
		./animation.c \
		./sprite.c \
		./state.c \
		./itos.c \
		./reset.c \
		./music.c \
		./score.c

OBJ =		$(SRC_BASIC:.c=.o)

NAME = 		my_hunter

FL = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS = -W -Wall -Wextra

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(FL)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

z:		fclean
		clear
