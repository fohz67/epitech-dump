/*
** EPITECH PROJECT, 2023
** manage_errors.c
** File description:
** manage_errors.c
*/

#include <stdbool.h>
#include <string.h>
#include "ginger.h"

static bool is_correct(const char c, int *occurences)
{
    if (c != '.' && c != 'T' && c != 'F' && c != 'G' && c != '\n') {
        return false;
    }
    if (c == 'T') {
        occurences[0] += 1;
    }
    if (c == 'F') {
        occurences[1] += 1;
    }
    if (c == 'G') {
        occurences[2] += 1;
    }
    return true;
}

int manage_errors_map(const char *buffer)
{
    int i = 0;
    int occ_i = 0;
    int occurences[3] = {0, 0, 0};

    while (buffer[i] != '\0') {
        if (is_correct(buffer[i], occurences) == false) {
            return 84;
        }
        i++;
    }
    while (occ_i < 3) {
        if (occurences[occ_i] == 0 && occ_i != 1) {
            return 84;
        }
        occ_i++;
    }
    return 0;
}

static int manage_errors_data(const char **av)
{
    int n_arg = 0;
    int i = 0;

    if (av[1][1] == 'm') {
        n_arg = 2;
    }
    if (av[3][1] == 'm') {
        n_arg = 4;
    }
    if (n_arg > 4) {
        return 84;
    }
    while (av[n_arg][i] != '\0') {
        if (av[n_arg][i] < '0' || av[n_arg][i] > '9') {
            return 84;
        }
        i++;
    }
    return 0;
}

int manage_errors(int ac, const char **av)
{
    if (ac != 5) {
        return 84;
    }
    if (strlen(av[1]) != 2 || strlen(av[3]) != 2) {
        return 84;
    }
    if (strcmp(av[1], "-f") != 0 && strcmp(av[1], "-m") != 0) {
        return 84;
    }
    if (strcmp(av[3], "-f") != 0 && strcmp(av[3], "-m") != 0) {
        return 84;
    }
    if (manage_errors_data(av) == 84) {
        return 84;
    }
    return 0;
}
