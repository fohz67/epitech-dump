/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display.c
*/

#include <stdio.h>
#include "my.h"

void my_display(double *src, int size)
{
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			printf("%.2f", src[x + (y * size)]);
			if (x != size - 1) {
				printf("\t");
			} else {
				printf("\n");
			}
		}
	}
}