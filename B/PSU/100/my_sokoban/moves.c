/*
** EPITECH PROJECT, 2022
** moves.c
** File description:
** moves.c
*/

#include "./include/my.h"

int char_checker(char c)
{
    if (c != WALL &&
        c != HOLE &&
        c != PLAYER &&
        c != CRATE &&
        c != ENDLINE &&
        c != SPACE) {
            return 1;
    }
    return 0;
}

int occu_checker(char *buffer)
{
    int player = 0;
    int crate = 0;
    int wall = 0;
    int hole = 0;
    int index = 0;

    while (buffer[index] != ENDSTR) {
        if (buffer[index] == WALL)
            wall++;
        if (buffer[index] == PLAYER)
            player++;
        if (buffer[index] == CRATE)
            crate++;
        if (buffer[index] == HOLE)
            hole++;
        index++;
    }
    if (player != 1 || crate == 0 || hole == 0 || wall < 12 || crate != hole)
        return 1;
    return 0;
}

int extraction(char *buffer, int line, int index)
{
    int total = 0;

    if (buffer[index - 1] == WALL && buffer[index + line] == WALL) {
        total = 1;
    }
    if (buffer[index - 1] == WALL && buffer[index - line] == WALL) {
        total = 1;
    }
    if (buffer[index + 1] == WALL && buffer[index + line] == WALL) {
        total = 1;
    }
    if (buffer[index + 1] == WALL && buffer[index - line] == WALL) {
        total = 1;
    }
    return total;
}

int check_moves(char *buffer, int line)
{
    int index = 0;
    int total = 0;
    int crates = 0;

    while (buffer[index] != ENDSTR) {
        if (buffer[index] == CRATE) {
            total = total + extraction(buffer, line, index);
            crates++;
        }
        index++;
    }
    if (total == crates) {
        return 0;
    }
    return 1;
}

int check(char *buffer, char *buffer2)
{
    int index = 0;
    int total = 0;
    int crates = 0;

    while (buffer[index] != ENDSTR) {
        if (buffer[index] == CRATE && buffer2[index] == HOLE) {
            total++;
        }
        if (buffer[index] == CRATE) {
            crates++;
        }
        index++;
    }
    if (total == crates) {
        return 0;
    }
    return 1;
}
