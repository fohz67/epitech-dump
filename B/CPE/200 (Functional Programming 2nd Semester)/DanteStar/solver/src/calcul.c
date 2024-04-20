/*
** EPITECH PROJECT, 2022
** calcul.c
** File description:
** calcul.c
*/

#include "solver.h"

int nb_col(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0' && buffer[i] != '\n') {
        i++;
    }
    return i;
}

int nb_line(char *buffer)
{
    int i = 0;
    int line = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            line++;
        }
        i++;
    }
    return line + 1;
}
