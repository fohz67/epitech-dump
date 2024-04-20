/*
** EPITECH PROJECT, 2022
** define_flags.c
** File description:
** define_flags.c
*/

#include "../include/my.h"

void define_flags(int ac, const char **av, char *flag)
{
    int index = 1;
    int length = 0;

    while (index < ac) {
        length = my_strlen(av[index]);
        if (av[index][0] == '-' && length == 2) {
            flags(av[index][1], flag);
        }
        if (av[index][0] == '-' && length > 2) {
            multiflags(av, flag, index);
        }
        index++;
    }
}
