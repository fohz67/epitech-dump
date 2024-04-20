##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = 	cat.c
MAIN = main.c
OBJ = 	$(SRC:.c=.o) $(MAIN:.c=.o)
NAME = 	cat
LIB = 	-L ../lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my
		gcc $(OBJ) -o $(NAME) $(LIB)
		make clean

test_run:
	make -C ../lib/my
	gcc -o unit_tests ../tests/test_cat.c $(SRC) $(LIB) --coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
