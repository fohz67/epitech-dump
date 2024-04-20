/*
** EPITECH PROJECT, 2023
** init_round.c
** File description:
** init_round.c
*/

#include <stdio.h>
#include "lingo.h"

char *init_round(int *verif)
{
    char *user_word = NULL;

    if (verif[0] == 1) {
        printf("\n\nRound %i\n", verif[1]);
        verif[0] = 0;
    }
    if ((user_word = read_user()) == NULL) {
        return NULL;
    }
    return user_word;
}
