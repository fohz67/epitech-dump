/*
** EPITECH PROJECT, 2022
** getters.c
** File description:
** getters.c
*/

#include "./include/my.h"

int pos(char *buffer, int index)
{
    while (buffer[index] != PLAYER) {
        index = index + 1;
    }
    return index;
}

int tap(char *buffer, char *buffer2, int index, int line)
{
    int key = getch();

    if (key == 32) {
        endwin();
        map(my_strcpy(buffer, buffer2), buffer2, my_strlen(buffer2), line);
    }
    if (key == KEY_LEFT && buffer[index - 1] != WALL) {
        index = left(buffer, buffer2, index);
    }
    if (key == KEY_UP && buffer[index - line] != WALL) {
        index = upp(buffer, buffer2, index, line);
    }
    if (key == KEY_RIGHT && buffer[index + 1] != WALL) {
        index = right(buffer, buffer2, index);
    }
    if (key == KEY_DOWN && buffer[index + line] != WALL) {
        index = down(buffer, buffer2, index, line);
    }
    return index;
}
