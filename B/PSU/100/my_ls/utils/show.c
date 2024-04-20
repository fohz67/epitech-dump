/*
** EPITECH PROJECT, 2022
** show.c
** File description:
** show.c
*/

#include "../include/my.h"

void show(char **tab, const char *path, int size, char *flag)
{
    char final_path[1000] = {0};
    int final_length = 0;

    my_strcpy(final_path, path);
    final_length = my_strlen(final_path);

    if (final_path[final_length] != '/') {
        my_strcat(final_path, "/");
        final_length = final_length + 1;
    }

    my_strcat(final_path, tab[size]);

    infos(final_path, flag);
    my_putstr(tab[size]);
    my_putchar('\n');

    final_path[0] = '\0';
}
