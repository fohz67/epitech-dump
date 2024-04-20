/*
** EPITECH PROJECT, 2022
** my_put_zero.c
** File description:
** My put zero
*/

#include "my.h"

int my_put_zero(int a, int power)
{
    int index = 1, length = 0;

    if (a == 1) {
        index = 10;
    }
    if (a == 0) {
        while (index <= power / 10) {
            index = index * 10;
            length = length + my_put_char('0');
        }
    } else {
        while (a * index <= power / 10 && a * index != 0) {
            index = index * 10;
            length = length + my_put_char('0');
        }
    }
    return length;
}
