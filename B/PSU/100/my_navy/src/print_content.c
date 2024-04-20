/*
** EPITECH PROJECT, 2022
** print_content.c
** File description:
** print_content.c
*/

#include "../include/my.h"

void edit_map_boat5(void)
{
    int x = my_game.buffer[27] - 48 + 1;
    int y = 2 + ((my_game.buffer[26] - 65) * 2);

    if (y % 2 != 0) {
        y = y + 1;
    }
    if (my_game.buffer[26] == my_game.buffer[29]) {
        my_game.my_map[x][y] = '5';
        my_game.my_map[x + 1][y] = '5';
        my_game.my_map[x + 2][y] = '5';
        my_game.my_map[x + 3][y] = '5';
        my_game.my_map[x + 4][y] = '5';
    } else {
        my_game.my_map[x][y] = '5';
        my_game.my_map[x][y + 2] = '5';
        my_game.my_map[x][y + 4] = '5';
        my_game.my_map[x][y + 6] = '5';
        my_game.my_map[x][y + 8] = '5';
    }
}

void edit_map_boat4(void)
{
    int x = my_game.buffer[19] - 48 + 1;
    int y = 2 + ((my_game.buffer[18] - 65) * 2);

    if (y % 2 != 0) {
        y = y + 1;
    }
    if (my_game.buffer[18] == my_game.buffer[21]) {
        my_game.my_map[x][y] = '4';
        my_game.my_map[x + 1][y] = '4';
        my_game.my_map[x + 2][y] = '4';
        my_game.my_map[x + 3][y] = '4';
    } else {
        my_game.my_map[x][y] = '4';
        my_game.my_map[x][y + 2] = '4';
        my_game.my_map[x][y + 4] = '4';
        my_game.my_map[x][y + 6] = '4';
    }
}

void edit_map_boat3(void)
{
    int x = my_game.buffer[11] - 48 + 1;
    int y = 2 + ((my_game.buffer[10] - 65) * 2);

    if (y % 2 != 0) {
        y = y + 1;
    }
    if (my_game.buffer[10] == my_game.buffer[13]) {
        my_game.my_map[x][y] = '3';
        my_game.my_map[x + 1][y] = '3';
        my_game.my_map[x + 2][y] = '3';
    } else {
        my_game.my_map[x][y] = '3';
        my_game.my_map[x][y + 2] = '3';
        my_game.my_map[x][y + 4] = '3';
    }
}

void edit_map_boat2(void)
{
    int x = my_game.buffer[3] - 48 + 1;
    int y = 2 + ((my_game.buffer[2] - 65) * 2);

    if (y % 2 != 0) {
        y = y + 1;
    }
    if (my_game.buffer[2] == my_game.buffer[5]) {
        my_game.my_map[x][y] = '2';
        my_game.my_map[x + 1][y] = '2';
    } else {
        my_game.my_map[x][y] = '2';
        my_game.my_map[x][y + 2] = '2';
    }
}

void print_map(void)
{
    int i = 0;

    edit_map_boat2();
    edit_map_boat3();
    edit_map_boat4();
    edit_map_boat5();

    write(1, "my positions:\n", 14);
    while (my_game.my_map[i] != NULL) {
        write(1, my_game.my_map[i], my_strlen(my_game.my_map[i]));
        i = i + 1;
    }
    i = 0;
    write(1, "\nenemy's positions:\n", 20);
    while (my_game.my_map[i] != NULL) {
        write(1, my_game.enemy_map[i], my_strlen(my_game.enemy_map[i]));
        i = i + 1;
    }
    my_putchar('\n');
}
