/*
** EPITECH PROJECT, 2023
** create_content.c
** File description:
** create_content.c
*/

#include <stdlib.h>
#include "hangman.h"

static int get_tries(int ac, const char *av[])
{
    int tries = 0;

    if (ac == 2) {
        tries = 10;
    } else {
        tries = atoi(av[2]);
    }
    return tries;
}

static int compute_data(int ac, const char *av[], char **array)
{
    char *word = NULL;
    int tries = 0;
    int result = 0;

    tries = get_tries(ac, av);
    if (tries < 1) {
        free_array(array);
        return 84;
    }
    word = choose_word(array);
    result = hangman(word, tries);
    free_array(array);
    return result;
}

int create_content(int ac, const char *av[])
{
    char *buffer = NULL;
    char **array = NULL;
    int result = 0;

    buffer = file_content(av[1]);
    if (buffer == NULL) {
        return 84;
    }
    array = my_tokarray(buffer, "\n");
    free(buffer);
    if (array == NULL) {
        return 84;
    }
    if (error(ac, av, array) == 84) {
        free_array(array);
        return 84;
    }
    result = compute_data(ac, av, array);
    return result;
}
