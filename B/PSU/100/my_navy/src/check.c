/*
** EPITECH PROJECT, 2022
** check.c
** File description:
** check.c
*/

#include "../include/my.h"

int check_pos_numbers(void)
{
    if (my_game.buffer[3] < '1' || my_game.buffer[3] > '8' ||
    my_game.buffer[11] < '1' || my_game.buffer[11] > '8' ||
    my_game.buffer[19] < '1' || my_game.buffer[19] > '8' ||
    my_game.buffer[27] < '1' || my_game.buffer[27] > '8') {
        return 84;
    }
    if (my_game.buffer[6] < '1' || my_game.buffer[6] > '8' ||
    my_game.buffer[14] < '1' || my_game.buffer[14] > '8' ||
    my_game.buffer[22] < '1' || my_game.buffer[22] > '8' ||
    my_game.buffer[30] < '1' || my_game.buffer[30] > '8') {
        return 84;
    }
    if (my_strlen(my_game.buffer) != 32) {
        return 84;
    }
    return 0;
}

int check_pos_letters(void)
{
    if (my_game.buffer[2] < 'A' || my_game.buffer[2] > 'H' ||
    my_game.buffer[10] < 'A' || my_game.buffer[10] > 'H' ||
    my_game.buffer[18] < 'A' || my_game.buffer[18] > 'H' ||
    my_game.buffer[26] < 'A' || my_game.buffer[26] > 'H') {
        return 84;
    }
    if (my_game.buffer[5] < 'A' || my_game.buffer[5] > 'H' ||
    my_game.buffer[13] < 'A' || my_game.buffer[13] > 'H' ||
    my_game.buffer[21] < 'A' || my_game.buffer[21] > 'H' ||
    my_game.buffer[29] < 'A' || my_game.buffer[29] > 'H') {
        return 84;
    }
    return check_pos_numbers();
}

int check_pos(void)
{
    if (my_game.buffer[0] != '2' ||
    my_game.buffer[8] != '3' ||
    my_game.buffer[16] != '4' ||
    my_game.buffer[24] != '5') {
        return 84;
    }
    if (my_game.buffer[1] != ':' ||
    my_game.buffer[9] != ':' ||
    my_game.buffer[17] != ':' ||
    my_game.buffer[25] != ':') {
        return 84;
    }
    if (my_game.buffer[4] != ':' ||
    my_game.buffer[12] != ':' ||
    my_game.buffer[20] != ':' ||
    my_game.buffer[28] != ':') {
        return 84;
    }
    return check_pos_letters();
}

int check_errors(int ac)
{
    if (ac < 2 || ac > 3) {
        return 84;
    }
    return check_pos();
}
