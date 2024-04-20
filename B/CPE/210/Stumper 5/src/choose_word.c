/*
** EPITECH PROJECT, 2023
** choose_word.c
** File description:
** choose_word.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <lingo.h>

static void print_instructions(char **array, int random_nb)
{
    int len_word = 0;

    len_word = my_strlen(array[random_nb]);
    printf("*: invalid letter\n");
    printf("?: incorrectly placed letter\n");
    printf("Will you find the secret word?\n");
    printf("%c", array[random_nb][0]);
    for (int i = 0; i < len_word - 1; i++) {
        printf("*");
    }
}

char *choose_word(char **array)
{
    int i = 0;
    int random_nb = 0;

    for (; array[i] != NULL; i++);
    if (i == 0) {
        return NULL;
    }
    random_nb = rand() % i;
    print_instructions(array, random_nb);
    return array[random_nb];
}
