/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static int create_all2(window *win, map_t **map)
{
    if (create_music(win) == 84)
        return 84;
    if (create_map_and_texture(win) == 84)
        return 84;
    if ((*map = create_all_object(*map, win)) == NULL)
        return 84;
    if (create_menu_game(win) == 84)
        return 84;
    if (create_characteristics(win) == 84)
        return 84;
    if (create_inventory(win) == 84)
        return 84;
    view_player(win);
    return 0;
}

int create_all(window *win, map_t **map)
{
    if (create_window(win) == 84)
        return 84;
    if (create_menu(win) == 84)
        return 84;
    if (create_settings(win) == 84)
        return 84;
    if (create_story(win) == 84)
        return 84;
    if (create_all_sprite(win) == 84)
        return 84;
    if (create_health_bar(win) == 84)
        return 84;
    if (create_all2(win, map) == 84)
        return 84;
    return 0;
}
