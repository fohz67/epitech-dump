/*
** EPITECH PROJECT, 2023
** env.c
** File description:
** env.c
*/

#include <stddef.h>
#include "my.h"

int my_env(char **envcp)
{
    int result = 0;

    for (int i = 0; envcp[i] != NULL; i++) {
        my_putstr(envcp[i]);
        my_putchar('\n');
    }
    return result;
}
