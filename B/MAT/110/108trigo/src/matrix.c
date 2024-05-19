/*
** EPITECH PROJECT, 2018
** matrix.c
** File description:
** matrix.c
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

void my_copy(double *dest, double *src, int len)
{
	memcpy(dest, src, sizeof(double) * len);
}

int my_equal(double *dest, double *src, int len)
{
	for (int i = 0; i < len; i++) {
		if (dest[i] != src[i]) {
			return 0;
		}
	}
	return 1;
}

int my_empty(double *src, int len)
{
	for (int i = 0; i < len; i++) {
		if (src[i] != 0) {
			return 0;
		}
	}
	return 1;
}

double *my_basic(int size, int len)
{
    double *mat = calloc(len, sizeof(double));

    if (mat == NULL) {
        return NULL;
	}
    for (int i = 0; i < size; i++) {
        mat[(size + 1) * i] = 1;
	}
    return mat;
}