/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update4.c
*/

#include "rpg.h"

static const char path[] = "assets/img/end_screen.png";

static int modify_texture(window *win)
{
    sfVector2f position = {win->caracters.player.x - 300,
    win->caracters.player.y - 200};
    sfVector2f size = {1920 / 3, 1080 / 3};

    sfRectangleShape_setPosition(win->story.rect, position);
    sfRectangleShape_setSize(win->story.rect, size);
    sfRectangleShape_setTexture(win->story.rect, win->story.texture, sfFalse);
    win->story.texture = sfTexture_createFromFile(path, NULL);
    if (win->story.texture == NULL) {
        return 84;
    }
    sfRectangleShape_setTexture(win->story.rect,
    win->story.texture, sfFalse);
    return 0;
}

int verif_state_grandpa(window *win)
{
    if (sfFloatRect_contains(&win->caracters.grandpa.detection,
    win->caracters.player.x, win->caracters.player.y)
    && sfKeyboard_isKeyPressed(sfKeyF) &&
    win->caracters.grandpa.isArround == false) {
        if (win->caracters.boss.death == true &&
        modify_texture(win) == 84) {
            return 84;
        }
        win->caracters.grandpa.isArround = true;
    }
    return 0;
}
