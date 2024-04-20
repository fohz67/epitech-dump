/*
** EPITECH PROJECT, 2023
** is_unstable.C
** File description:
** check if the grid is unstable
*/

#include <stdlib.h>
#include <stdbool.h>

bool is_unstable(int *grid_nb)
{
    for (int i = 0; grid_nb[i]; i++) {
        if (grid_nb[i] >= 4) {
            return (true);
        }
    }
    return (false);
}
