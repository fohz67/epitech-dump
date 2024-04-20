/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** get_rooms.c
*/

#include <stdlib.h>
#include "lemin.h"

static int get_room2(char **array)
{
    int i = 0;
    int result = 0;

    for (; array[i] != NULL; i++) {
        if (my_isnbr(array[i]) == false && i < 3) {
            return -1;
        }
        if (array[i][0] != '#' && i > 2) {
            return -1;
        }
    }
    if (i < 3) {
        return -1;
    }
    result = my_getnbr(array[0]);
    return result;
}

int get_room(char *line)
{
    int result;
    char **array = NULL;

    if (line == NULL) {
        return -1;
    }
    array = my_tokarray(line, " \t\n");
    if (array == NULL) {
        free(line);
        return -1;
    }
    result = get_room2(array);
    free(line);
    my_free_array(array);
    return result;
}
