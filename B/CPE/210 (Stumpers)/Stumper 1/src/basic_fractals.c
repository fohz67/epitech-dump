/*
** EPITECH PROJECT, 2023
** basic_fractals.c
** File description:
** basic_fractals.c
*/

#include "my.h"

void print_one_fractal(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '@') {
            my_putchar('\n');
        } else {
            my_putchar(buffer[i]);
        }
        i++;
    }
    my_putchar('\n');
}

int basic_fractals(char *first_pattern, int size)
{
    if (size == 0) {
        my_putstr("#\n");
    }
    if (size == 1) {
        print_one_fractal(first_pattern);
    }
    return 0;
}
