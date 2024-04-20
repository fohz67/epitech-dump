/*
** EPITECH PROJECT, 2022
** concat_params.c
** File description:
** Concat params
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int a = 0;
    char *str = malloc(sizeof(char) * argc);

    while (a < argc) {
        my_strcat(str, argv[a]);
        if (my_strlen(argv[a]) > 0 && argc > a)
            my_strcat(str, "\n");
        a = a + 1;
    }
    return str;
}
