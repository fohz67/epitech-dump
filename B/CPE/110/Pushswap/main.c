/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, const char **av)
{
    int result = 0;

    if (ac < 2) {
        return 84;
    }
    if (ac == 2) {
        my_putchar('\n');
        return 0;
    }

    result = create_tab(ac, av);
    return result;
}
