/*
** EPITECH PROJECT, 2022
** my_advanced_sort_array.c
** File description:
** My advanced sort array
*/

#include "include/my.h"

static int my_strcmp_ptr(char *s1, char *s2)
{
    my_strcmp(s1, s2);
}

int my_advanced_sort_word_array(
    char **tab,
    int(*cmp)(char const *, char const *))
{
    cmp = &my_strcmp_ptr;

    for (int a = 0; tab[a] != '\0'; a) {
        if (cmp(tab[a], tab[a + 1] > 0)) {
            my_swap(&tab[a], &tab[a + 1]);
            a = 0;
        } else {
            a = a + 1;
        }
    }
    return 0;
}
