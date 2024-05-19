/*
** EPITECH PROJECT, 2018
** build.c
** File description:
** build.c
*/

#include <stdlib.h>
#include "my.h"

struct request *my_build_struct(void)
{
	struct request *req = malloc(sizeof(struct request));

	if (req == NULL) {
		return NULL;
	}
	req->callback = 0;
	return req;
}

struct request *my_build_instance(struct request *req, int ac, char **av)
{
    req->content = malloc(sizeof(double) * (ac - 2));
    req->result = malloc(sizeof(double) * (ac - 2));
    req->len = ac - 2;
    req->size = sqrt(ac - 2);
    if (req->content == NULL || req->result == NULL) {
        return NULL;
    }
    my_type(req, av[1]);
    for (int i = 2; i < ac; i++) {
        req->content[i - 2] = atof(av[i]);
    }
    return req;
}