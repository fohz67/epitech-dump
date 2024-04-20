/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include <stdlib.h>
#include "rpg.h"

static const char *background_path = "assets/img/ancient.png";

static void rect(window *win)
{
    sfVector2f position = {0, 0};
    sfVector2f size = {1920, 1080};

    sfRectangleShape_setPosition(win->story.rect, position);
    sfRectangleShape_setSize(win->story.rect, size);
    sfRectangleShape_setTexture(win->story.rect, win->story.texture, sfFalse);
}

static void text(window *win)
{
    sfVector2f position = {530, 310};

    sfText_setCharacterSize(win->story.text, 45);
    sfText_setColor(win->story.text, sfWhite);
    sfText_setOutlineColor(win->story.text, sfBlack);
    sfText_setOutlineThickness(win->story.text, 3);
    sfText_setLineSpacing(win->story.text, 1.1);
    sfText_setString(win->story.text, history);
    sfText_setPosition(win->story.text, position);
    sfText_setFont(win->story.text, win->font);
}

int create_story(window *win)
{
    win->story.rect = sfRectangleShape_create();
    win->story.text = sfText_create();
    win->story.state = 0;
    win->story.texture = sfTexture_createFromFile (background_path, NULL);
    if (win->texture == NULL) {
        return 84;
    }
    rect(win);
    text(win);
    return 0;
}
