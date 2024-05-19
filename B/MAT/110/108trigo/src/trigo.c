/*
** EPITECH PROJECT, 2018
** trigo.c
** File description:
** trigo.c
*/

#include <stdlib.h>
#include "my.h"

void my_exp(struct request *req)
{
	double *array = malloc(sizeof(double) * req->len);
	double *tmp = malloc(sizeof(double) * req->len);
	double *current = malloc(sizeof(double) * req->len);
	double fac = 1;

	if (req->result == NULL || array == NULL || tmp == NULL || current == NULL) {
		req->callback = 84;
		return;
	}
	req->result = my_basic(req->size, req->len);
	my_copy(array, req->content, req->len);
	req->result = my_add(req->result, req->content, req->len);
	for (int i = 2; i < 200; i++) {
		my_copy(current, req->result, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		fac *= i;
		my_copy(tmp, array, req->len);
		tmp = my_div(tmp, fac, req->len, req->size);
		req->result = my_add(req->result, tmp, req->len);
		free(tmp);
		if (my_process_stop(req, current) == true) {
			break;
		}
	}
	free(array);
	free(current);
}

void my_cos(struct request *req)
{
	double *array = malloc(sizeof(double) * req->len);
	double *tmp = malloc(sizeof(double) * req->len);
	double *current = malloc(sizeof(double) * req->len);
	double fac = 2;
	int j = 2;
	int i = 2;

	if (req->result == NULL || array == NULL || tmp == NULL || current == NULL) {
		req->callback = 84;
		return;
	}
	req->result = my_basic(req->size, req->len);
	my_copy(array, req->content, req->len);
	while (i < 200) {
		my_copy(current, req->result, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		my_copy(tmp, array, req->len);
		tmp = my_div(tmp, fac, req->len, req->size);
		if (i % 2) {
			req->result = my_add(req->result, tmp, req->len);
		} else {
			req->result = my_sub(req->result, tmp, req->len);
		}
		free(tmp);
		array = my_mult(array, req->content, req->len, req->size);
		i++;
		fac *= ++j;
		fac *= ++j;
		if (my_process_stop(req, current) == true) {
			break;
		}
	}
	free(array);
	free(current);
}

void my_sin(struct request *req)
{
	double *array = malloc(sizeof(double) * req->len);
	double *tmp = malloc(sizeof(double) * req->len);
	double *current = malloc(sizeof(double) * req->len);
	double fac = 6;
	int i = 2;
	int j = 3;

	if (req->result == NULL || array == NULL || tmp == NULL || current == NULL) {
		req->callback = 84;
		return;
	}
	my_copy(array, req->content, req->len);
	my_copy(req->result, req->content, req->len);
	while (i < 200) {
		my_copy(current, req->result, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		array = my_mult(array, req->content, req->len, req->size);
		my_copy(tmp, array, req->len);
		tmp = my_div(tmp, fac, req->len, req->size);
		if (i % 2) {
			req->result = my_add(req->result, tmp, req->len);
		}
		else {
			req->result = my_sub(req->result, tmp, req->len);
		}
		free(tmp);
		i++;
		fac *= ++j;
		fac *= ++j;
		if (my_process_stop(req, current) == true) {
			break;
		}
	}
	free(array);
	free(current);
}

void my_acos(struct request *req)
{
	double *array = malloc(sizeof(double) * req->len);
	double *tmp = malloc(sizeof(double) * req->len);
	double *current = malloc(sizeof(double) * req->len);
	double fac = 2;
	int i = 2;
	int j = 2;

	if (req->result == NULL || array == NULL || tmp == NULL || current == NULL) {
		req->callback = 84;
		return;
	}
	req->result = my_basic(req->size, req->len);
	my_copy(array, req->content, req->len);
	while (i < 200) {
		my_copy(current, req->result, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		my_copy(tmp, array, req->len);
		tmp = my_div(tmp, fac, req->len, req->size);
		req->result = my_add(req->result, tmp, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		free(tmp);
		i++;
		fac *= ++j;
		fac *= ++j;
		if (my_process_stop(req, current) == true) {
			break;
		}
	}
	free(array);
	free(current);
}

void my_asin(struct request *req)
{
	double *array = malloc(sizeof(double) * req->len);
	double *tmp = malloc(sizeof(double) * req->len);
	double *current = malloc(sizeof(double) * req->len);
	double fac = 6;
	int i = 2;
	int j = 3;

	if (req->result == NULL || array == NULL || tmp == NULL || current == NULL) {
		req->callback = 54;
		return;
	}
	my_copy(array, req->content, req->len);
	my_copy(req->result, req->content, req->len);
	while (i < 200) {
		my_copy(current, req->result, req->len);
		array = my_mult(array, req->content, req->len, req->size);
		array = my_mult(array, req->content, req->len, req->size);
		my_copy(tmp, array, req->len);
		tmp = my_div(tmp, fac, req->len, req->size);
		req->result = my_add(req->result, tmp, req->len);
		free(tmp);
		i++;
		fac *= ++j;
		fac *= ++j;
		if (my_process_stop(req, current) == true) {
			break;
		}
	}
	free(array);
	free(current);
}