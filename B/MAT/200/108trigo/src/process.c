/*
** EPITECH PROJECT, 2018
** process.c
** File description:
** process.c
*/

#include "my.h"

int my_process(struct request *req)
{
    if (req->type == EXP) {
        my_exp(req);
    } else if (req->type == COS) {
        my_cos(req);
    } else if (req->type == SIN) {
        my_sin(req);
    } else if (req->type == COSH) {
        my_acos(req);
    } else if (req->type == SINH) {
        my_asin(req);
    }
    my_display(req->result, req->size);
    return req->callback;
}

bool my_process_stop(struct request *req, double *current)
{
	if (my_equal(req->result, current, req->len)) {
		return true;
	}
	if (my_empty(req->result, req->len)) {
		my_copy(req->result, current, req->len);
		return true;
	}
	return false;
}