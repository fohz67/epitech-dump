/*
** EPITECH PROJECT, 2022
** mixword.h
** File description:
** file.h of the project
*/

#include <stdbool.h>

#ifndef MIXWORD_
    #define MIXWORD_

    char **my_tokarray(char *buffer, char *separators);
    int my_strlen(const char *str);
    void free_array(char **array);
    char *file_content(const char *path);
    int error(int ac, const char *av[]);
    int create_content(const char *av[], int size);
    char **create_grid(char **array, int size);
    bool is_lowercase(char *buffer);
    void print_grid(char **grid, char **array, int size);
#endif
