/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

int main(int ac, const char **av)
{
    char *buffer = NULL;
    char **maze = NULL;
    char **maze_cpy = NULL;

    if (ac != 2)
        return 84;
    if ((buffer = (file_content(av[1]))) == NULL)
        return 84;
    if (error(buffer) == 84)
        return 84;
    if (buffer[0] == 'X' || buffer[my_strlen(buffer)] == 'X') {
        printf("no solution found\n");
        return 0;
    } else {
        buffer[0] = '#';
    }
    if ((maze = my_str_to_word_array(buffer)) == NULL ||
        (maze_cpy = my_str_to_word_array(buffer)) == NULL)
        return 84;
    return solver(maze, maze_cpy, buffer);
}
