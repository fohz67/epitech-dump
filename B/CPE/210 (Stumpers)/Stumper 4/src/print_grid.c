/*
** EPITECH PROJECT, 2023
** print_grid.c
** File description:
** print the grid
*/

#include <stdio.h>

void print_grid(char **grid, char **array, int size)
{
    int words = 0;
    int max_words = 0;

    for (; array[max_words] != NULL; max_words++);
    if (max_words > size)
        words = size;
    else
        words = max_words;
    printf("%d/%d words inserted in the grid.\n", words, max_words);
    for (int i = 0; i != size + 2; i++)
        printf("+");
    printf("\n");
    for (int i = 0; i != size; i++)
        printf("|%s|\n", grid[i]);
    for (int i = 0; i != size + 2; i++)
        printf("+");
    printf("\n");
}
