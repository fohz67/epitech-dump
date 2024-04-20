/*
** EPITECH PROJECT, 2022
** my_put_char.c
** File description:
** My put char
*/

#include <unistd.h>
#include "my.h"

int my_put_char(char c)
{
    write(1, &c, 1);
    return 1;
}
