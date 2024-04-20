/*
** EPITECH PROJECT, 2022
** handling.c
** File description:
** handling.c
*/

#include "../include/my.h"

int handling(char *buffer, int size, struct square b)
{
    int lines = 0;
    int obs = 0;
    int nbline = my_nbline(buffer);
    int index = my_nbrlen(nbline);
    while (index < size) {
        char ch = buffer[index];
        char ch1 = buffer[index + 1];
        if (ch != WATER && ch != OBSTACLE && ch != ENDLINE && ch != ENDSTR)
            return ERROR;
        if (ch == ENDLINE && (ch1 == WATER || ch1 == OBSTACLE))
            lines = lines + 1;
        if (ch == OBSTACLE)
            obs = obs + 1;
        index = index + 1;
    }
    if (nbline != lines)
        return ERROR;
    if (obs == 0)
        return algorithm_nobstacle(my_str_to_word_array(buffer), buffer, size);
    return algorithm(my_str_to_word_array(buffer), buffer, size, b);
}
