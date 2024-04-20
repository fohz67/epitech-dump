/*
** EPITECH PROJECT, 2022
** sandpile.h
** File description:
** file.h of the project
*/

#include <stdbool.h>

#ifndef SANDPILE_
    #define SANDPILE_

    int error(const char **av, char *grid);
    char *file_content(const char *path);
    void sandpile(char *grid, int *grid_nb, int iteration);
    bool is_unstable(int *grid_nb);
    void create_grid_nb(char *grid, int *grid_nb, const char *template);

#endif
