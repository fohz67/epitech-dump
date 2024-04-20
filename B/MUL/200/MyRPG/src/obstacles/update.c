/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include "lib.h"
#include "rpg.h"

static int display_object(window *win, map_t *map, int type, sfVector2f *pos)
{
    map_t *tmp = NULL;

    if (type >= 0) {
        tmp = get_node(map, type);
        sfSprite_setPosition(tmp->sprite, (*pos));
        sfRenderWindow_drawSprite(win->window, tmp->sprite, NULL);
        (*pos).x += 40;
    }
    if (type < 0) {
        (*pos).x += 40;
    }
    return 0;
}

int display_back(window *win, map_t *map)
{
    sfVector2f pos = {0, 0};
    int type = 0;

    for (int i = 0; win->map_texture.map_back[i] != NULL; i++) {
        for (int j = 0; win->map_texture.map_back[i][j] != '\0'; j++) {
            type = check_type_object(win->map_texture.map_back[i][j]);
            display_object(win, map, type, &pos);
        }
        pos.x = 0;
        pos.y += 40;
    }
    return 0;
}

int display_map(window *win, map_t *map)
{
    sfVector2f pos = {997, 680};
    int type = 0;

    for (int i = 0; win->map_texture.map_front[i] != NULL; i++) {
        for (int j = 0; win->map_texture.map_front[i][j] != '\0'; j++) {
            type = check_type_object(win->map_texture.map_front[i][j]);
            display_object(win, map, type, &pos);
        }
        pos.x = 997;
        pos.y += 40;
    }
    return 0;
}
