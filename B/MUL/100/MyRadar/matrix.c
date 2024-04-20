/*
** EPITECH PROJECT, 2022
** matrix.c
** File description:
** matrix.c
*/

#include "./include/my.h"

void matrix_content(char *buffer, struct utils *utils)
{
    int index = 0;

    while (buffer[index] != ENDSTR) {
        if (buffer[index] == TOWER) {
            utils->total_tower = utils->total_tower + 1;
        }
        if (buffer[index] == PLANE) {
            utils->total_plane = utils->total_plane + 1;
        }
        index = index + 1;
    }

    utils->tab = my_str_to_word_antitab_array(buffer);
}
