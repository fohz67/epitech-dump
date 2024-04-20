/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create.c
*/

#include "rpg.h"

static const char menu_bg_path[] = "assets/img/menu_background.png";
static const char font_path[] = "assets/font/font.ttf";

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
unsigned int bpp, int type)
{
    sfVideoMode vmod = {x, y, bpp};

    return (sfRenderWindow_create(vmod, "Supremacy", sfClose | type, NULL));
}

int create_window(window *win)
{
    win->window = create_renderwindow(1920, 1080, 32, sfResize);
    win->background = sfSprite_create();
    win->texture = sfTexture_createFromFile (menu_bg_path, NULL);
    win->font = sfFont_createFromFile(font_path);
    if (win->texture == NULL ||
        win->font == NULL) {
        return 84;
    }
    win->position.x = 0;
    win->position.y = 0;
    win->state = 0;
    win->collid_nb = 0;
    sfSprite_setPosition(win->background, win->position);
    sfSprite_setTexture(win->background, win->texture, sfFalse);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    return 0;
}
