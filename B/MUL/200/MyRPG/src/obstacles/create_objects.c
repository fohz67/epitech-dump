/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_objects.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"
#include "lib.h"

static const sfIntRect rect[] = {
    {55, 0, 48, 48},
    {1, 241, 40, 40},
    {290, 50, 40, 40},
    {385, 140, 48, 100},
    {0, 0, 176, 177},
    {50, 241, 45, 45},
    {100, 243, 48, 48},
    {144, 248, 40, 40},
    {188, 243, 48, 48},
    {340, 244, 48, 48},
    {0, 0, 140, 140},
    {144, 0, 48, 48},
    {341, 49, 45, 40},
    {200, 200, 45, 45},
    {0, 0, 413, 337},
    {0, 0, 425, 500},
    {0, 286, 144, 144},
};

static const sfVector2f size[] = {
    {1, 1},
    {1, 1},
    {1, 1},
    {1.5, 1.5},
    {1, 1},
    {1, 1},
    {1, 1},
    {0.4, 0.4},
    {1, 1},
    {1, 1},
    {0.6, 0.6},
    {1, 1},
    {1, 1},
    {1, 1},
    {0.8, 0.8},
    {0.04, 0.04},
    {0.6, 0.6}
};

static const int texture[] = {
    0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 3, 4, 5, 4, 6, 7, 3
};

map_t *get_node(map_t *map, int index)
{
    map_t *tmp = NULL;
    int i = 0;

    tmp = map;
    while (tmp != NULL) {
        if (i == index) {
            return tmp;
        }
        tmp = tmp->next;
        i++;
    }
    return NULL;
}

static map_t *add_object(map_t *map, map_t *new)
{
    map_t *tmp = NULL;

    tmp = map;
    if (map == NULL) {
        return new;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return map;
}

static map_t *create_object(map_t *map, int index, window *win)
{
    map_t *new = NULL;

    if ((new = malloc(sizeof(map_t))) == NULL) {
        return NULL;
    }
    new->sprite = NULL;
    new->rect = rect[index];
    new->next = NULL;
    if ((new->sprite = sfSprite_create()) == NULL) {
        return NULL;
    }
    sfSprite_setTexture(new->sprite,
    win->map_texture.texture[texture[index]], sfFalse);
    sfSprite_setTextureRect(new->sprite, rect[index]);
    sfSprite_setScale(new->sprite, size[index]);
    map = add_object(map, new);
    return map;
}

map_t *create_all_object(map_t *map, window *win)
{
    for (int i = 0; i < 17; i++) {
        if ((map = create_object(map, i, win)) == NULL) {
            return NULL;
        }
    }
    return map;
}
