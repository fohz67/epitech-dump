/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file of the project
*/

#include <stdlib.h>
#include <time.h>
#include "lingo.h"

int main(int ac, const char *av[])
{
    int result = 0;

    if (ac != 2) {
        return 84;
    }
    srand(time(NULL));
    result = create_content(av[1]);
    return result;
}
