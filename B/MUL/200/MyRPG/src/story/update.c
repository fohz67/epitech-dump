/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update.c
*/

#include <stdbool.h>
#include "rpg.h"

static const char *path = "assets/img/help.png";

int update_event_story(window *win, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEnter &&
    win->caracters.grandpa.isEnd == true) {
        return 42;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEnter &&
    win->story.state == 0 && win->state == 1) {
        win->story.state = 1;
        return 0;
    }
    if (event->type == sfEvtKeyReleased && event->key.code ==
    sfKeyEnter && win->story.state == 1 && win->state == 1) {
        win->state = 2;
    }
    return 0;
}

void update_story(window *win)
{
    sfVector2f position = {250, 240};

    sfRenderWindow_drawRectangleShape(win->window, win->story.rect, NULL);
    if (win->story.state == 0) {
        sfRenderWindow_drawText(win->window, win->story.text, NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && win->story.state == 1) {
        win->caracters.player.x = 1400;
        win->caracters.player.y = 1265;
        sfSprite_setPosition(win->caracters.player.sprite, position);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && win->story.state == 0) {
        win->story.texture = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(win->story.rect,
        win->story.texture, sfFalse);
    }
}
