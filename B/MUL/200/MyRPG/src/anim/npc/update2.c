/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update2.c
*/

#include "rpg.h"

static void verif_zone_grandpa2(window *win)
{
    if (win->caracters.grandpa.isArround == true &&
    win->caracters.boss.death == true) {
        sfRenderWindow_drawRectangleShape(win->window, win->story.rect, NULL);
        win->caracters.grandpa.isEnd = true;
    }
    if (!sfFloatRect_contains(&win->caracters.grandpa.detection,
    win->caracters.player.x, win->caracters.player.y))
        win->caracters.grandpa.isArround = false;
}

static int verif_zone_grandpa(window *win)
{
    if (verif_state_grandpa(win) == 84) {
        return 84;
    }
    if (win->caracters.grandpa.isArround == true &&
    win->caracters.boss.death != true) {
        sfRenderWindow_drawSprite(win->window, win->caracters.grandpa.dialog,
        NULL);
        sfSprite_setPosition(win->caracters.grandpa.dialog, (sfVector2f)
        {win->caracters.player.x - 120, win->caracters.player.y + 60});
        win->caracters.grandpa.isQuestActive = true;
    }
    verif_zone_grandpa2(win);
    return 0;
}

int check_zone_grandpa(window *win)
{
    sfVector2f origin = {40.f, 35.f};

    sfCircleShape_setPosition(win->caracters.grandpa.circle,
    win->caracters.grandpa.position);
    sfCircleShape_setOrigin(win->caracters.grandpa.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->caracters.grandpa.circle,NULL);
    win->caracters.grandpa.detection =
    sfCircleShape_getGlobalBounds(win->caracters.grandpa.circle);
    if (verif_zone_grandpa(win) == 84) {
        return 84;
    }
    return 0;
}

static void verif_zone_parchment(window *win)
{
    if (sfFloatRect_contains(&win->parchment.detection,
    win->caracters.player.x, win->caracters.player.y)
    && sfKeyboard_isKeyPressed(sfKeyF) &&
    win->parchment.isArround == false) {
        win->parchment.isArround = true;
    }
    if (win->parchment.isArround == true) {
        sfVector2f position = {win->caracters.player.x + 80,
        win->caracters.player.y - 90};
        sfRenderWindow_drawSprite(win->window, win->parchment.dialog, NULL);
        sfSprite_setPosition(win->parchment.dialog, position);
    }
    if (!sfFloatRect_contains(&win->parchment.detection,
    win->caracters.player.x, win->caracters.player.y)) {
        win->parchment.isArround = false;
    }
}

void check_zone_parchment(window *win)
{
    sfVector2f origin = {20.f, 16.f};
    sfVector2f position = {3200, 1800};

    sfCircleShape_setPosition(win->parchment.circle,
    position);
    sfCircleShape_setOrigin(win->parchment.circle, origin);
    sfRenderWindow_drawCircleShape(win->window,
    win->parchment.circle,NULL);
    win->parchment.detection =
    sfCircleShape_getGlobalBounds(win->parchment.circle);
    verif_zone_parchment(win);
}
