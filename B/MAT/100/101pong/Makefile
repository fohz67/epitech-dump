##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	pong.c

NAME	=	101pong

$(NAME): $(OBJ)
	gcc -lm -Wall -Wextra -I. -o $(NAME) $(SRC)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
