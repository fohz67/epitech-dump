/*
** EPITECH PROJECT, 2022
** resources.c
** File description:
** resources.c
*/

#include "paint.h"

static int dialog_toolbar_res(struct gui *gui)
{
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile("textures/close.png", NULL);
    if (!texture || texture == NULL) {
        return 84;
    }
    gui->text_menu.texture = texture;
    return 0;
}

static int tool_res(struct gui *gui)
{
    int i = 0;

    while (i < TOOLS) {
        sfTexture *texture = sfTexture_createFromFile(texture_tool(i), NULL);
        if (!texture || texture == NULL) {
            return 84;
        }
        gui->tool[i].texture = texture;
        i++;
    }
    return 0;
}

static int gui_res(struct gui *gui)
{
    sfFont *font = NULL;
    sfTexture *texture = NULL;
    sfTexture *color = NULL;
    sfTexture *black = NULL;

    font = sfFont_createFromFile("fonts/font.ttf");
    texture = sfTexture_createFromFile("textures/cursor_gui.png", NULL);
    color = sfTexture_createFromFile("textures/colors.png", NULL);
    black = sfTexture_createFromFile("textures/black.png", NULL);
    if (!font || !texture || !color || !black || font == NULL ||
    texture == NULL || color == NULL || black == NULL) {
        return 84;
    }
    gui->font = font;
    gui->cursor.texture = texture;
    gui->color.color_picker = color;
    gui->color.black_picker = black;
    return 0;
}

int resources_create(struct gui *gui)
{
    if (gui_res(gui) == 84) {
        return 84;
    }
    if (tool_res(gui) == 84) {
        return 84;
    }
    if (dialog_toolbar_res(gui) == 84) {
        return 84;
    }
    return 0;
}
