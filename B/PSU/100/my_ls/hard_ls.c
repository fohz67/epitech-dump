/*
** EPITECH PROJECT, 2022
** multiple_flag.c
** File description:
** multiple_flag.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include "./include/my.h"

int title(char *name, char *occ, char *flag, int position)
{
    DIR* directory = NULL;
    directory = opendir(name);
    struct stat sb;
    if (directory == NULL && stat(name, &sb) == -1)
        return 0;
    if (directory == NULL && stat(name, &sb) != -1) {
        if (position > 0 && flag[3] == 'n')
            my_putchar('\n');
        infos(name, flag);
        my_putstr(name);
        my_putchar('\n');
        return 0;
    }
    if (occ[2] == 'y' && flag[3] == 'n') {
        if (position > 0)
            my_putchar('\n');
        my_putstr(name);
        my_putstr(":\n");
    }
    return 0;
}

char* mydup(int index, const char **av, char *path, char *occ)
{
    if (occ[1] == 'y') {
        path = my_strdup(av[index]);
    } else {
        path = my_strdup(".");
    }
    return path;
}

int hard_ls(int ac, const char **av, char *flag)
{
    char occ[3] = "nnn";
    char *path = NULL;
    int index = 1;
    int position = 0;
    int result = 0;

    occurences(ac, av, occ);
    while (index < ac) {
        path = mydup(index, av, path, occ);
        if (path[0] != '-') {
            title(path, occ, flag, position++);
            result = result + tabling(path, flag);
        }
        index++;
    }
    if (result >= 84)
        return 84;
    else
        return result;
}
