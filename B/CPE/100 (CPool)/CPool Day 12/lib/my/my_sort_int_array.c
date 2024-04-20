/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** My sort int array
*/

#include "my.h"

void my_sort_int_array(int *array, int *size)
{
    int a = 0;
    int b = 0;
    int size_int = *size;

    while (a < size_int) {
        a = a + 1;
        while (b < size_int - a - 1) {
            b = b + 1;
            my_swap(&a, &b);
        }
    }
}
