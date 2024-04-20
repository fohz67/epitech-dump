/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** get_rooms.c
*/

#include <stdlib.h>
#include "lemin.h"

static int get_tunnel2(char **array, anthill *ant, bool status)
{
    int i = 0;

    for (; array[i] != NULL; i++) {
        if (my_isnbr(array[i]) == false && i < 2) {
            return -1;
        }
        if (array[i][0] != '#' && i > 1) {
            return -1;
        }
        if (status == true && i < 2) {
            ant->tunnels[ant->tunnel_index][i] = my_getnbr(array[i]);
        }
    }
    if (i < 2) {
        return -1;
    }
    if (status == true) {
        ant->tunnel_index++;
    }
    return 0;
}

int get_tunnel(char *line, anthill *ant, bool status)
{
    int result = 0;
    char **array = NULL;

    if (line == NULL) {
        return -1;
    }
    array = my_tokarray(line, "- \t\n");
    if (array == NULL) {
        free(line);
        return -1;
    }
    result = get_tunnel2(array, ant, status);
    free(line);
    my_free_array(array);
    return result;
}
