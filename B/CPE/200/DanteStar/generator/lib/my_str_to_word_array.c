/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "generator.h"

static void my_tab(const char *str, char **tab, int words)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < words) {
        tab[i] = malloc(my_lenword(str, j) + 1);
        k = 0;
        while (str[j] != '\0' && my_issep(str[j]) == 1) {
            tab[i][k] = str[j];
            j = j + 1;
            k = k + 1;
        }
        tab[i][k] = '\0';
        j = j + 1;
        i = i + 1;
    }
    tab[i] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    int words = my_nbword(str);
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (words + 1));
    if (tab == NULL) {
        return NULL;
    }
    my_tab(str, tab, words);
    return tab;
}
