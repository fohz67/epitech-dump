/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_collisions.c
*/

#include <stdlib.h>
#include "lib.h"
#include "rpg.h"

static void set_item(window *win, sfVector2f pos, sfVector2f size)
{
    win->collid[win->collid_nb].rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(win->collid[win->collid_nb].rect, pos);
    sfRectangleShape_setSize(win->collid[win->collid_nb].rect, size);
    win->collid_nb++;
}

static void collid_type2(char **array, int i, int j, window *win)
{
    if (array[i][j] == 'T' || array[i][j] == 'i') {
        sfVector2f size = {40, 40};
        sfVector2f pos = {j * 40 + 997, i * 40 + 680 + 25};
        set_item(win, pos, size);
    }
    if (array[i][j] == 'h' || array[i][j] == 'A') {
        sfVector2f size = {90, 70};
        sfVector2f pos = {j * 40 + 997, i * 40 + 680 + 40};
        set_item(win, pos, size);
    }
    if (array[i][j] == 'c') {
        sfVector2f size = {20, 16};
        sfVector2f pos = {j * 40 + 997, i * 40 + 680 + 25};
        set_item(win, pos, size);
    }
}

static void collid_type(char **array, int i, int j, window *win)
{
    if (array[i][j] == 'W') {
        sfVector2f size = {40, 40};
        sfVector2f pos = {j * 40, i * 40};
        set_item(win, pos, size);
    }
    if (array[i][j] == 'H') {
        sfVector2f size = {142, 108};
        sfVector2f pos = {j * 40 + 997 + 18, i * 40 + 680 + 60};
        set_item(win, pos, size);
    }
    if (array[i][j] == 'E') {
        sfVector2f size = {330, 120};
        sfVector2f pos = {j * 40 + 997, i * 40 + 680 + 160};
        set_item(win, pos, size);
    }
    collid_type2(array, i, j, win);
}

int create_collid2(window *win, char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            collid_type(array, i, j, win);
        }
    }
    return 0;
}

int create_collid(window *win, char **array, int size)
{
    if ((win->collid = malloc(sizeof(collid) * size)) == NULL) {
        return 84;
    }
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            collid_type(array, i, j, win);
        }
    }
    return 0;
}
