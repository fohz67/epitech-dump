/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

int main(int ac, char **av)
{
	struct request *req = my_build_struct();
	int callback = 0;

	if (ac == 2 && my_strcmp(av[1], HELP_ARG) == 0) {
		my_putstr(HELP);
		return 0;
	}
	if (my_valid_params(ac, av) == false) {
		return 84;
	}
	my_build_instance(req, ac, av);
	callback = my_process(req);
	free(req->content);
	free(req->result);
	free(req);
	return callback;
}