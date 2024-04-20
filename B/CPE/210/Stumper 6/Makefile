##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LIB =			./lib/my_tokarray.c \
			./lib/my_strlen.c \
			./lib/my_free.c

SRC =			./src/main.c \
			./src/error.c \
			./src/buffer.c \
			./src/choose_word.c \
			./src/create_content.c \
			./src/read_user.c \
			./src/hangman.c \

OBJ =			$(LIB:.c=.o) \
			$(SRC:.c=.o)

NAME = 			hangman

CFLAGS = 		-I ./include -W -Wall -Wextra

$(NAME):		$(OBJ)
			gcc $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
			rm -f $(OBJ)
			find . \( -name "#*#" -o -name "*~" \) -delete

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
