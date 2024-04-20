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
						./lib/my_strdup.c \
						./lib/my_sort_time.c \
                        ./lib/my_sort_ascii.c

SRC_BASIC =		./basic_ls.c \
			./hard_ls.c \
			./dispatcher.c

SRC_UTILS = 		./utils/flags.c \
			./utils/multiflags.c \
			./utils/infos.c \
			./utils/define_flags.c \
			./utils/occurences.c \
			./utils/tabling.c \
			./utils/display.c \
			./utils/blksize.c \
			./utils/timecheck.c \
			./utils/show.c


OBJ =			$(SRC_LIB:.c=.o) \
			$(SRC_BASIC:.c=.o) \
			$(SRC_UTILS:.c=.o)

NAME = 			my_ls

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
