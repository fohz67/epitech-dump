/*
** EPITECH PROJECT, 2018
** values.c
** File description:
** values.c
*/

#include "my.h"

void my_type(struct request *req, char *str)
{
	if (my_strcmp(str, "EXP") == 0) {
		req->type = EXP;
	}
	if (my_strcmp(str, "COS") == 0) {
		req->type = COS;
	}
	if (my_strcmp(str, "SIN") == 0) {
		req->type = SIN;
	}
	if (my_strcmp(str, "COSH") == 0) { 
		req->type = COSH;
	}
	if (my_strcmp(str, "SINH") == 0) {
		req->type = SINH;
	}
}