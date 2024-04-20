/*
** EPITECH PROJECT, 2023
** get_theme.c
** File description:
** get_theme.c
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "scripting.h"

char *return_theme(char **file, int i)
{
    char **name = NULL;
    char *theme = NULL;

    if (strstr(file[i], "42SH_THEME") != NULL) {
        if (file[i][0] != '#' && check_string(file[i]) != 2 &&
        check_syntax(file[i]) != 1) {
        }
        name = my_tokarray(file[i], "\"");
        if (name == NULL) {
            return NULL;
        }
        theme = malloc(sizeof(char) * my_strlen(name[1]) + 1);
        if (theme == NULL) {
            free_array(name);
            return NULL;
        }
        theme = strcpy(theme, name[1]);
        free_array(name);
    }
    return theme;
}

char *get_theme(char **file)
{
    char *theme = NULL;

    if (file == NULL)
        return NULL;
    for (int i = 0; file[i] != NULL; i++) {
        if (theme == NULL)
            theme = return_theme(file, i);
    }
    return theme;
}
