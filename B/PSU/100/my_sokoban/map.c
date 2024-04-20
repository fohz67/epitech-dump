/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** map.c
*/

#include "./include/my.h"

void invalid(void)
{
    clear();
    mvaddstr(LINES / 2, COLS / 2 - 20, INVALID_SIZE);
    refresh();
}

int end (int result)
{
    endwin();
    return result;
}

int initialize(void)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    refresh();

    return 0;
}

int map(char *buffer, char *buffer2, int size, int line)
{
    int index = 0;
    int result = 44;
    index = pos(buffer, index);
    initialize();
    while (result == 44) {
        if (check(buffer, buffer2) == 0)
            result = 0;
        if (check_moves(buffer, line) == 0 && result != 0)
            result = 1;
        if (COLS >= line && LINES >= size / line) {
            mvaddstr(0, 0, buffer);
            refresh();
        } else {
            invalid();
        }
        if (result == 44)
            index = tap(buffer, buffer2, index, line);
    }
    return end(result);
}
