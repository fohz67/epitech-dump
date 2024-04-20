/*
** EPITECH PROJECT, 2022
** keys.c
** File description:
** keys.c
*/

#include "./include/my.h"

int left(char *buffer, char *buffer2, int index)
{
    if (buffer[index - 1] == CRATE &&
    buffer[index - 2] != WALL && buffer[index - 2] != CRATE) {
        buffer[index - 2] = CRATE;
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index - 1] = PLAYER;
    }
    if (buffer[index - 1] != CRATE) {
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index - 1] = PLAYER;
    }
    return index;
}

int upp(char *buffer, char *buffer2, int index, int line)
{
    if (buffer[index - line] == CRATE &&
    buffer[index - line * 2] != WALL && buffer[index - line * 2] != CRATE) {
        buffer[index - line * 2] = CRATE;
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index - line] = PLAYER;
    }
    if (buffer[index - line] != CRATE) {
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index - line] = PLAYER;
    }
    return index;
}

int right(char *buffer, char *buffer2, int index)
{
    if (buffer[index + 1] == CRATE &&
    buffer[index + 2] != WALL && buffer[index + 2] != CRATE) {
        buffer[index + 2] = CRATE;
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index + 1] = PLAYER;
    }
    if (buffer[index + 1] != CRATE) {
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index + 1] = PLAYER;
    }
    return index;
}

int down(char *buffer, char *buffer2, int index, int line)
{
    if (buffer[index + line] == CRATE &&
    buffer[index + line * 2] != WALL && buffer[index + line * 2] != CRATE) {
        buffer[index + line * 2] = CRATE;
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index + line] = PLAYER;
    }
    if (buffer[index + line] != CRATE) {
        buffer[index] = buffer2[index] == HOLE ? HOLE : SPACE;
        buffer[index = index + line] = PLAYER;
    }
    return index;
}
