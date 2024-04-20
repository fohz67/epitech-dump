/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error.c
*/

#include "solver.h"

int error_condition(char c, int line_len, int count)
{
    if (c == '\n') {
        if (line_len != count) {
            return -2;
        }
        count = -1;
    }
    return count;
}

int error3(char *buffer)
{
    int i = 0;
    int line_len = 0;
    int count = 0;

    line_len = nb_col(buffer);

    while (buffer[i] != '\0') {
        if ((count = error_condition(buffer[i], line_len, count)) == -2) {
            return 84;
        }
        i++;
        count++;
    }
    if (line_len != count) {
        return 84;
    }
    return 0;
}

int error(char *buffer)
{
    int i = 0;
    int len = 0;
    int star = 0;

    len = my_strlen(buffer);
    if (len < 1)
        return 84;
    while (buffer[i] != '\0') {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n')
            return 84;
        if (buffer[i] == '*')
            star++;
        i++;
    }
    if (error3(buffer) == 84)
        return 84;
    return 0;
}
