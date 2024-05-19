/*
** EPITECH PROJECT, 2018
** cal.c
** File description:
** cal.c
*/

#include <stdlib.h>
#include "my.h"

double *my_div(double *src, double k, int len, int size)
{
    double *mat = NULL;

    mat = malloc(sizeof(double) * len);
	if (mat == NULL) {
		return NULL;
    }
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			mat[x + (y * size)] = src[x + (y * size)] / k;
        }
    }
	return mat;
}


double *my_mult(double *src, double *obj, int len, int size)
{
    double *mat = NULL;

	mat = malloc(sizeof(double) * len);
    if (mat == NULL) {
        return NULL;
    }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            double sum = 0;
            double *src_row = src + (y * size);
            double *obj_col = obj + x;
            for (int i = 0; i < size; i++, src_row++, obj_col += size) {
                sum += (*src_row) * (*obj_col);
            }
            mat[x + (y * size)] = sum;
        }
    }
    return mat;
}

double *my_add(double *src, double *obj, int len)
{
	double *mat = NULL;

	mat = calloc(len, sizeof(double));
	if (mat == NULL) {
		return NULL;
	}
	for (int i = 0; i < len; i++) {
		mat[i] = src[i] + obj[i];
	}
	return mat;
}

double *my_sub(double *src, double *obj, int len)
{
    double *mat = NULL;

	mat = calloc(len, sizeof(double));
    if (mat == NULL) {
        return NULL;
	}
    for (int i = 0; i < len; i++) {
        mat[i] = src[i] - obj[i];
	}
    return mat;
}