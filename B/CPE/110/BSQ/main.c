/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "./include/my.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        return file_content(av[1]);;
    }
    if (ac == 3) {
        return generate(av);
    }
    return ERROR;
}
