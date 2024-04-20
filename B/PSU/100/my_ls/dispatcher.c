/*
** EPITECH PROJECT, 2022
** my_ls.c
** File description:
** my_ls.c
*/

#include "./include/my.h"

int my_ls(int ac, const char **av)
{
    char flag[6] = "nnnnnn";
    define_flags(ac, av, flag);

    if (ac == 1) {
        return basic_ls(ac, av);
    } else {
        return hard_ls(ac, av, flag);
    }
    return 0;
}

int main(int ac, const char **av)
{
    return my_ls(ac, av);
}
