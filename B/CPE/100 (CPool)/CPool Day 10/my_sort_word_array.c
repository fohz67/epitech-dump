/*
** EPITECH PROJECT, 2022
** my_sort_word_array.c
** File description:
** My sort word array
*/

#include "include/my.h"

int my_sort_word_array(char **tab)
{
    for (int a = 0; tab[a] != '\0'; a) {
        if (my_strcmp(tab[a], tab[a + 1] > 0)) {
            my_swap(&tab[a], &tab[a + 1]);
            a = 0;
        } else {
            a = a + 1;
        }
    }
    return 0;
}
