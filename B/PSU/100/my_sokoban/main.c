/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr(HELP);
        return 0;
    }
    return file_content(av[1]);
}
