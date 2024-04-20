/*
** EPITECH PROJECT, 2022
** tool_create.c
** File description:
** tool_create.c
*/

#include <stdbool.h>
#include "paint.h"

static void tool_size(struct gui *gui, int i)
{
    sfVector2f size_tool = {100, 100};
    sfVector2f size_image = {50, 50};

    sfRectangleShape_setSize(gui->tool[i].rect, size_tool);
    sfRectangleShape_setSize(gui->tool[i].image, size_image);
    sfRectangleShape_setSize(gui->tool[i].shadow, size_tool);
}

static void tool_color(struct gui *gui, int i)
{
    sfColor color_image = {255, 255, 255, 135};
    sfColor color_shadow = {210, 216, 236, 255};

    sfRectangleShape_setFillColor(gui->tool[i].rect, sfWhite);
    sfRectangleShape_setFillColor(gui->tool[i].shadow, color_shadow);
    sfRectangleShape_setFillColor(gui->tool[i].image, color_image);
    sfRectangleShape_setTexture(gui->tool[i].image, gui->tool[i].texture,
    sfTrue);
}

static void tool_position(struct gui *gui, int i)
{
    sfVector2f position_tool = {1775, 100};
    sfVector2f position_image = {1800, 125};
    sfVector2f position_shadow = {1765, 110};

    position_tool.y += 120 * i;
    position_image.y += 120 * i;
    position_shadow.y += 120 * i;
    sfRectangleShape_setPosition(gui->tool[i].rect, position_tool);
    sfRectangleShape_setPosition(gui->tool[i].image, position_image);
    sfRectangleShape_setPosition(gui->tool[i].shadow, position_shadow);
}

void tool_create(struct gui *gui)
{
    int i = 0;

    while (i < TOOLS) {
        gui->tool[i].rect = sfRectangleShape_create();
        gui->tool[i].image = sfRectangleShape_create();
        gui->tool[i].shadow = sfRectangleShape_create();
        tool_size(gui, i);
        tool_color(gui, i);
        tool_position(gui, i);
        i++;
    }
    gui->tool[0].isLClicked = true;
}
