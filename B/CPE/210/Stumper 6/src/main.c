/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <time.h>
#include "hangman.h"

int main(int ac, const char *av[])
{
    int result = 0;

    if (ac != 2 && ac != 3) {
        return 84;
    }
    srand(time(NULL));
    result = create_content(ac, av);
    return result;
}
