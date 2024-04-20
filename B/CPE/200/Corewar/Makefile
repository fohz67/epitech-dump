##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

build:
	make -C ./lib
	make -C ./asm
	make -C ./corewar

all:	build

clean:
	make clean -C ./lib
	make clean -C ./asm
	make clean -C ./corewar

fclean:	clean
	make fclean -C ./lib
	make fclean -C ./asm
	make fclean -C ./corewar

re:	fclean all

.PHONY:	all clean fclean re

debug:
	make re -C ./lib
	make debug -C ./asm
	make debug -C ./corewar
