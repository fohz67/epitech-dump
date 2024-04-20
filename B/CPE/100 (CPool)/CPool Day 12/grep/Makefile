##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = 	grep.c
MAIN = main.c
GREP_SUB = grep_sub.c
OBJ = 	$(SRC:.c=.o) $(MAIN:.c=.o) $(GREP_SUB:.c=.o)
NAME = 	grep
LIB = 	-L ../lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my
		gcc $(OBJ) -o $(NAME) $(LIB)
		make clean

test_run:
	make -C ../lib/my
	gcc -o unit_tests ../tests/test_grep.c $(SRC) $(GREP_SUB) $(LIB) --coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
