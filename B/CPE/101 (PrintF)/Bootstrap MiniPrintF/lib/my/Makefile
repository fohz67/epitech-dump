##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = 	./my_putchar.c \
	./my_put_nbr.c \
	./my_putstr.c \
	./my_strlen.c

OBJ =		$(SRC:.c=.o)
NAME_LIBMY =	libmy.a

all:	$(NAME_LIBMY)

$(NAME_LIBMY):	$(OBJ)
		ar rc $(NAME_LIBMY) $(OBJ)
		cp $(NAME_LIBMY) ../$(NAME_LIBMY)
		make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME_LIBMY)

re:	fclean all
