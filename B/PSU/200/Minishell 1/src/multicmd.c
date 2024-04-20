/*
** EPITECH PROJECT, 2022
** engine.c
** File description:
** engine.c
*/

#include <stdio.h>
#include "my.h"

int size_multi_command(char *buffer)
{
    int size = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';') {
            size++;
        }
    }
    return size;
}
