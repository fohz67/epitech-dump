/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error file of the project
*/

#include <string.h>
#include <stdbool.h>

static bool is_nbr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

bool is_lowercase(const char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!(buffer[i] == '\n' || (buffer[i] >= 'a' && buffer[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}

int error(int ac, const char *av[])
{
    if (strcmp(av[1], "-f") != 0) {
        return 84;
    }
    if (ac == 3) {
        return 0;
    }
    if (strcmp(av[3], "-s") != 0) {
        return 84;
    }
    if (is_nbr(av[4]) == false) {
        return 84;
    }
    return 0;
}
