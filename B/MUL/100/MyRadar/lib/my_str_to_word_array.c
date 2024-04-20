/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../include/my.h"

void my_malloc(const char *str, char **tab, int occu)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (a < occu + 1) {
        c = 0;
        while (str[b] != ENDSTR && str[b] != ENDLINE) {
            b = b + 1;
            c = c + 1;
        }
        tab[a] = malloc(sizeof(char) * (c + 1));
        a = a + 1;
        b = b + 1;
    }
    tab[a] = malloc(sizeof(char) * (my_strlen(END)) + 1);
}

void my_tab(const char *str, char **tab, int occu)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (a < occu + 1) {
        c = 0;
        while (str[b] != ENDSTR && str[b] != ENDLINE) {
            tab[a][c] = str[b];
            b = b + 1;
            c = c + 1;
        }
        tab[a][c] = ENDSTR;
        a = a + 1;
        b = b + 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int occu = my_nbword(str);
    char **tab = malloc(sizeof(char *) * (occu + 2));

    my_malloc(str, tab, occu);
    my_tab(str, tab, occu);

    tab[occu + 1] = END;
    return tab;
}
