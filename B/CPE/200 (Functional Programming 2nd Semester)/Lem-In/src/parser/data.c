/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** data.c
*/

#include "lemin.h"

static int read_data5(char *line, anthill *ant)
{
    if (ant->data_index == 0) {
        ant->nb_rooms++;
    }
    if (ant->data_index == 3) {
        if (ant->start_index + ant->end_index != 2) {
            return 84;
        }
        my_putstr("#tunnels\n");
        ant->data_index = 4;
    }
    if (ant->data_index == 4 &&
    get_tunnel(my_strdup(line), ant, true) == -1) {
        return 84;
    }
    return 0;
}

static int read_data4(char *line, anthill *ant)
{
    if (ant->data_index == 0 &&
    get_room(my_strdup(line)) == -1 &&
    get_tunnel(my_strdup(line), ant, false) == -1) {
        return 84;
    }
    if (ant->data_index != 4 &&
    get_room(my_strdup(line)) == -1 &&
    get_tunnel(my_strdup(line), ant, false) == 0) {
        ant->data_index = 3;
    }
    if (read_data5(line, ant) == 84) {
        return 84;
    }
    return 0;
}

static int read_data3(char *line, anthill *ant)
{
    if (ant->start_room == -1 && ant->data_index == 1) {
        ant->start_room = get_room(my_strdup(line));
        if (ant->start_room == -1)
            return 84;
        ant->nb_rooms++;
        ant->data_index = 0;
        return 0;
    }
    if (ant->end_room == -1 && ant->data_index == 2) {
        ant->end_room = get_room(my_strdup(line));
        if (ant->end_room == -1)
            return 84;
        ant->nb_rooms++;
        ant->data_index = 0;
        return 0;
    }
    if (read_data4(line, ant) == 84) {
        return 84;
    }
    return 0;
}

static int read_data2(char *line, anthill *ant)
{
    if (my_strncmp(line, "##start\n", 8) == 0) {
        if (ant->data_index != 0)
            return 84;
        ant->data_index = 1;
        if (ant->start_index++ > 1)
            return 84;
        return 0;
    }
    if (my_strncmp(line, "##end\n", 6) == 0) {
        if (ant->data_index != 0)
            return 84;
        ant->data_index = 2;
        if (ant->end_index++ > 1)
            return 84;
        return 0;
    }
    if (read_data3(line, ant) == 84)
        return 84;
    return 0;
}

int read_data(char *line, anthill *ant)
{
    if (ant->nb_ant == -1) {
        if (get_ants(line, ant) == -1)
            return 84;
        return 0;
    }
    if (read_data2(line, ant) == 84) {
        return 84;
    }
    my_putstr_parser(line);
    return 0;
}
