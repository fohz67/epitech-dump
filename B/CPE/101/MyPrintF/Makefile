##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	./my_display.c \
	./my_get_alpha.c \
	./my_get_digit.c \
	./my_get_double_len.c \
	./my_get_int_len.c \
	./my_get_int.c \
	./my_get_num.c \
	./my_get_power.c \
	./my_get_zero.c \
	./my_printf.c \
	./my_put_char.c \
	./my_put_e.c \
	./my_put_f.c \
	./my_put_g.c \
	./my_put_int.c \
	./my_put_nbase.c \
	./my_put_space.c \
	./my_put_space.c \
	./my_put_string.c \
	./my_put_string_format.c \
	./my_get_string_len.c \
	./my_put_unsigned.c \
	./my_put_u_format.c \
	./my_get_unsigned_len.c \
	./my_put_int_format.c \
	./my_put_zero.c

OBJ =		$(SRC:.c=.o)
NAME_LIBMY =	libmy.a
NAME_MYH =	my.h

all:	$(NAME_LIBMY)

$(NAME_LIBMY):	$(OBJ)
		ar rc $(NAME_LIBMY) $(OBJ)
		make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME_LIBMY)

re:	fclean all
