/*
** EPITECH PROJECT, 2018
** errors.c.c
** File description:
** errors.c
*/

#include <stdbool.h>
#include "my.h"

static bool valid_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-') {
			return false;
		}
	}
	return true;
}

bool my_valid_params(int ac, char **av)
{
	if (ac == 1) {
		return false;
	}
	if (my_strcmp(av[1], "EXP") != 0 && my_strcmp(av[1], "COS") != 0 && my_strcmp(av[1], "SIN") != 0 && my_strcmp(av[1], "COSH") != 0 && my_strcmp(av[1], "SINH") != 0) {
		return false;
	}
	for (int i = 2; i < ac; i++) {
		if (valid_number(av[i]) == false) {
			return false;
		}
	}
	if ((ac - 2) != 1 && (ac - 2) != 4 && (ac - 2) != 9 && (ac - 2) != 16 && (ac - 2) != 25) {
		return false;
	}
	if (sqrt(ac - 2) != (int)sqrt(ac - 2)) {
		return false;
	}
	return true;
}
