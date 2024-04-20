/*
** EPITECH PROJECT, 2023
** 
** File description:
** 
*/

#include <stdio.h>
#include "ginger.h"

void print_map(const char **map, int token, int token_max, int mv_left)
{
    printf("Tokens: %i/%i\n", token, token_max);
    printf("Movement points: %i\n", mv_left);
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
    printf("%c", '\n');
}

void condition_win(int token, int token_max)
{
    if (token == token_max) {
        printf("Ginger never loses!");
    } else {
        printf("Ginger is too old for that!");
    }
}

