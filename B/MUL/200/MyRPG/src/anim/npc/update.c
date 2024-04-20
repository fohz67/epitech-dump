/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update.c
*/

#include "rpg.h"
#include <stdio.h>

void event_key_f(window *win, sfEvent *event)
{
    if (sfFloatRect_contains(&win->chest.detection,
    win->caracters.player.x, win->caracters.player.y)
    && event->type == sfEvtKeyReleased && event->key.code == sfKeyF &&
    win->chest.isArround == false) {
        win->chest.isArround = true;
        win->chest.count++;
    }
}

static void verif_zone_forestboy(window *win)
{
    if (sfFloatRect_contains(&win->caracters.forestboy.detection,
    win->caracters.player.x, win->caracters.player.y)
    && sfKeyboard_isKeyPressed(sfKeyF) &&
    win->caracters.forestboy.isArround == false) {
        win->caracters.forestboy.isArround = true;
    }
    if (win->caracters.forestboy.isArround == true) {
        sfVector2f position = {win->caracters.player.x - 120,
        win->caracters.player.y + 60};
        sfRenderWindow_drawSprite(win->window, win->caracters.forestboy.dialog,
        NULL);
        sfSprite_setPosition(win->caracters.forestboy.dialog, position);
    }
    if (!sfFloatRect_contains(&win->caracters.forestboy.detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->caracters.forestboy.isArround = false;
    }
}

static void check_zone_forestboy(window *win)
{
    sfVector2f origin = {40.f, 35.f};

    sfCircleShape_setPosition(win->caracters.forestboy.circle,
    win->caracters.forestboy.position);
    sfCircleShape_setOrigin(win->caracters.forestboy.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.forestboy.circle, NULL);
    win->caracters.forestboy.detection =
    sfCircleShape_getGlobalBounds(win->caracters.forestboy.circle);
    verif_zone_forestboy(win);
}

int update_pnj(window *win)
{
    if (check_zone_grandpa(win) == 84) {
        return 84;
    }
    check_zone_forestboy(win);
    check_zone_woman(win);
    check_zone_parchment(win);
    if (check_zone_chest(win) == 84)
        return 84;
    if (win->caracters.grandpa.isEnd != true) {
        sfRenderWindow_drawSprite(win->window,
        win->caracters.grandpa.sprite, NULL);
    }
    sfRenderWindow_drawSprite(win->window,
    win->caracters.woman.sprite, NULL);
    sfRenderWindow_drawSprite(win->window,
    win->caracters.forestboy.sprite, NULL);
    return 0;
}
