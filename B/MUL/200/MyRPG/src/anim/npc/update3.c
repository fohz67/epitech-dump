/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update3.c
*/

#include "rpg.h"

static void verif_zone_woman(window *win)
{
    if (sfFloatRect_contains(&win->caracters.woman.detection,
    win->caracters.player.x, win->caracters.player.y)
    && sfKeyboard_isKeyPressed(sfKeyF) &&
    win->caracters.woman.isArround == false) {
        win->caracters.woman.isArround = true;
    }
    if (win->caracters.woman.isArround == true) {
        sfVector2f position = {win->caracters.player.x - 120,
        win->caracters.player.y + 60};
        sfRenderWindow_drawSprite(win->window, win->caracters.woman.dialog,
        NULL);
        sfSprite_setPosition(win->caracters.woman.dialog, position);
    }
    if (!sfFloatRect_contains(&win->caracters.woman.detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->caracters.woman.isArround = false;
    }
}

void check_zone_woman(window *win)
{
    sfVector2f origin = {40.f, 35.f};

    sfCircleShape_setPosition(win->caracters.woman.circle,
    win->caracters.woman.position);
    sfCircleShape_setOrigin(win->caracters.woman.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.woman.circle, NULL);
    win->caracters.woman.detection =
    sfCircleShape_getGlobalBounds(win->caracters.woman.circle);
    verif_zone_woman(win);
}

static int verif_zone_chest(window *win)
{
    if (win->chest.isArround == true && win->chest.count == 1) {
        sfVector2f position = {win->caracters.player.x  - 120,
        win->caracters.player.y + 60};
        sfRenderWindow_drawSprite(win->window, win->chest.dialog_found, NULL);
        sfSprite_setPosition(win->chest.dialog_found, position);
        if (add_item_inventory(win, "assets/img/sword_chest.png",
        sparkling_sword, "sparkling sword") == 84)
            return 84;
    }
    if (win->chest.isArround == true && win->chest.count > 1) {
        sfVector2f position = {win->caracters.player.x  - 120,
        win->caracters.player.y + 60};
        sfRenderWindow_drawSprite(win->window, win->chest.dialog_empty, NULL);
        sfSprite_setPosition(win->chest.dialog_empty, position);
    }
    if (!sfFloatRect_contains(&win->chest.detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->chest.isArround = false;
    }
    return 0;
}

int check_zone_chest(window *win)
{
    sfVector2f origin = {20.f, 16.f};
    sfVector2f position = {1025, 725};

    sfCircleShape_setPosition(win->chest.circle,
    position);
    sfCircleShape_setOrigin(win->chest.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->chest.circle,NULL);
    win->chest.detection =
    sfCircleShape_getGlobalBounds(win->chest.circle);
    if (verif_zone_chest(win) == 84)
        return 84;
    return 0;
}
