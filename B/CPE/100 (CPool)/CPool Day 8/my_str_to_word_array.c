/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** My str to word array
*/

#include <stdlib.h>

int my_is_alpha (char *str)
{
    if (str < '0')
        return 1;
    if (str > '9' && str < 'A')
        return 1;
    if (str > 'Z' && str < 'a')
        return 1;
    if (str > 'z')
        return 1;
    return 0;
}

int my_nb_word(char *str)
{
    int nb = 0;
    int a = 0;

    while (str[a] != '\0') {
        if (my_is_alpha(str[a]) == 1)
            nb = nb + 1;
        a = a + 1;
    }
    return nb + 1;
}

void my_malloc(char *str, char **tab, int word)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (a < word - 1) {
        c = 0;
        while (str[b] != '\0' && my_is_alpha(str[b] == 0)) {
            b = b + 1;
            c = c + 1;
        }
        tab[a] = malloc(sizeof(char) * (c + 1));
        a = a + 1;
        b = b + 1;
    }
}

void my_tab(char *str, char **tab, int word)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (a < word - 1) {
        c = 0;
        while (str[b] != '\0' && my_is_alpha(str[b] == 0)) {
            tab[a][c] = str[b];
            b = b + 1;
            c = c + 1;
        }
        tab[a][c] = '\0';
        a = a + 1;
        b = b + 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int word = my_nb_word(str);
    char **tab = malloc(sizeof(char *) * (word + 1));
    tab[word] = NULL;

    my_malloc(str, tab, word);
    my_tab(str, tab, word);
    free(tab);
    return tab;
}
