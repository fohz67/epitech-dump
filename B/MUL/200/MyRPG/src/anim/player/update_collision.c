/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_collision.c
*/

#include "rpg.h"

static int update_collision4(window *win)
{
    if (win->key == sfKeyS) {
        win->caracters.player.y -= win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    if (win->key == sfKeyD) {
        win->caracters.player.x -= win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    return 0;
}

static int update_collision3(window *win)
{
    if (win->key == sfKeyZ) {
        win->caracters.player.y += win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    if (win->key == sfKeyQ) {
        win->caracters.player.x += win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    return 0;
}

static int update_collision2(window *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        win->caracters.player.x -= win->caracters.player.speed;
        win->caracters.player.y += win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        win->caracters.player.x += win->caracters.player.speed;
        win->caracters.player.y += win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return 1;
    }
    return 0;
}

void update_collision(window *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        win->caracters.player.x -= win->caracters.player.speed;
        win->caracters.player.y -= win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        win->caracters.player.x += win->caracters.player.speed;
        win->caracters.player.y -= win->caracters.player.speed;
        sfRenderWindow_drawSprite(win->window,
        win->caracters.player.sprite, NULL);
        return;
    }
    if (update_collision2(win) == 1)
        return;
    if (update_collision3(win) == 1)
        return;
    if (update_collision4(win) == 1)
        return;
}
