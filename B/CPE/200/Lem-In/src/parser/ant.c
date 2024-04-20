/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-lemin-benjamin.gayaud
** File description:
** get_rooms.c
*/

#include <stdlib.h>
#include "lemin.h"

int get_ants(char *line, anthill *ant)
{
    line[my_strlen(line) - 1] = '\0';
    if (my_isnbr(line) == false) {
        return -1;
    }
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            line[i - 1] = '\n';
            line[i] = '\0';
        }
    }
    ant->nb_ant = my_getnbr(line);
    if (ant->nb_ant <= 0) {
        return -1;
    }
    my_putstr("#number_of_ants\n");
    my_putnbr(ant->nb_ant);
    my_putstr("\n#rooms\n");
    return 0;
}
