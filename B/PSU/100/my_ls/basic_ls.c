/*
** EPITECH PROJECT, 2022
** single_dot.c
** File description:
** single_dot.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include "./include/my.h"

int display_basic(char **tab, int size)
{
    int index = 0;

    my_sort_ascii(size, tab);

    while (index < size) {
        my_putstr(tab[index++]);
        my_putchar('\n');
    }
    return index;
}

int basic_ls(int ac, const char **av)
{
    DIR* directory = NULL;
    struct dirent* current = NULL;

    char *tab[1000] = {0};
    int index = 0;

    directory = opendir(".");
    while ((current = readdir(directory)) != NULL && index < 900) {
        if (current->d_name[0] != '.') {
            tab[index++] = my_strdup(current->d_name);
        }
    }
    closedir(directory);
    display_basic(tab, index);
    return 0;
}
