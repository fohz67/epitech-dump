/*
** EPITECH PROJECT, 2023
** choose_word.c
** File description:
** choose_word.c
*/

#include <stdlib.h>
#include "hangman.h"

char *choose_word(char **array)
{
    int i = 0;
    int random_nb = 0;

    for (; array[i] != NULL; i++);
    if (i == 0) {
        return NULL;
    }
    random_nb = rand() % i;
    return array[random_nb];
}
