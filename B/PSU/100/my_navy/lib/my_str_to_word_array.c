/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../include/my.h"

char **my_tab(const char *str, char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < 10) {
        tab[i] = malloc(sizeof(char) * (17 + 1));
        k = 0;
        while (k < 18) {
            tab[i][k] = str[j];
            j = j + 1;
            k = k + 1;
        }
        tab[i][k] = '\0';
        i = i + 1;
    }
    tab[i] = NULL;
    return tab;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = NULL;

    if ((tab = malloc(sizeof(char *) * (10 + 1))) == NULL) {
        return NULL;
    }
    tab = my_tab(str, tab);
    return tab;
}
