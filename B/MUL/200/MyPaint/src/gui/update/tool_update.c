/*
** EPITECH PROJECT, 2022
** tool_update.c
** File description:
** tool_update.c
*/

#include <stdbool.h>
#include "paint.h"

static void tool_manage(struct gui *gui, sfRenderWindow *window, int i)
{
    sfColor color_hover = {210, 216, 236, 255};

    if (gui->tool[i].isLClicked == true || gui->tool[i].isRClicked == true) {
        sfRectangleShape_setFillColor(gui->tool[i].rect, sfWhite);
        sfRectangleShape_setOutlineColor(gui->tool[i].rect, color_hover);
        sfRectangleShape_setOutlineThickness(gui->tool[i].rect, 5);
    } else if (gui->tool[i].isHover == true) {
        sfRectangleShape_setFillColor(gui->tool[i].rect, color_hover);
        sfRectangleShape_setOutlineThickness(gui->tool[i].rect, 0);
    } else {
        sfRectangleShape_setFillColor(gui->tool[i].rect, sfWhite);
        sfRectangleShape_setOutlineThickness(gui->tool[i].rect, 0);
        sfRenderWindow_drawRectangleShape(window, gui->tool[i].shadow, NULL);
    }

}

void tool_update(struct gui *gui, sfRenderWindow *window)
{
    int i = 0;
    sfColor color_palette = {gui->color.r, gui->color.g, gui->color.b, 255};

    while (i < TOOLS) {
        tool_manage(gui, window, i);
        sfRectangleShape_setFillColor(gui->tool[2].rect, color_palette);
        sfRenderWindow_drawRectangleShape(window, gui->tool[i].rect, NULL);
        sfRenderWindow_drawRectangleShape(window, gui->tool[i].image, NULL);
        i++;
    }
}
