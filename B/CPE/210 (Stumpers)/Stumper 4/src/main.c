/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file of the project
*/

#include <stdlib.h>
#include <time.h>
#include "mixword.h"

int main(int ac, const char *av[])
{
    int result = 0;
    int size = 8;

    if (ac != 3 && ac != 5) {
        return 84;
    }
    if (error(ac, av) == 84) {
        return 84;
    }
    if (ac == 5) {
        size = atoi(av[4]);
    }
    srand(time(NULL));
    result = create_content(av, size);
    return result;
}
