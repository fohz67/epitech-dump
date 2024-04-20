/*
** EPITECH PROJECT, 2022
** tabling.c
** File description:
** tabling.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include "../include/my.h"

int tabling_ok(const char *path, DIR* directory, char *flag)
{
    struct dirent* current = NULL;
    char *tab[1000] = {0};
    int index = 0;

    if (flag[3] == 'y') {
        tab[index++] = my_strdup(path);
        display(tab, ".", flag, index);
        return 0;
    }
    while ((current = readdir(directory)) != NULL && index < 900) {
        if (flag[0] == 'y')
            tab[index++] = my_strdup(current->d_name);
        if (flag[0] == 'n' && current->d_name[0] != '.')
            tab[index++] = my_strdup(current->d_name);
    }
    display(tab, path, flag, index);
    return 0;
}

int tabling(const char *path, char *flag)
{
    DIR* directory = NULL;

    directory = opendir(path);

    if (directory == NULL) {
        return 84;
    } else {
        tabling_ok(path, directory, flag);
    }

    closedir(directory);
    return 0;
}
