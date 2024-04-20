/*
** EPITECH PROJECT, 2022
** gui.c
** File description:
** gui.c
*/

#include <stdlib.h>
#include "paint.h"

static void gui_create_custom_size(struct gui *gui)
{
    int i = 0;
    int radius[TOOLS] = {20, 20, 20, 20};
    gui->cursor.all_radius = malloc(TOOLS);

    while (i < TOOLS) {
        gui->cursor.all_radius[i] = radius[i];
        i++;
    }
}

static void gui_create_variables(struct gui *gui)
{
    gui->color.r = 255;
    gui->color.g = 0;
    gui->color.b = 0;
    gui->color.a = 255;
    gui->cursor.tool = 0;
    gui->cursor.dg = -1;
    gui->cursor.tool_radius = 20;
    gui->cursor.eraser_type = 1;
    gui->cursor.isOnSheet = false;
    gui->text_menu.isShowed = false;
    gui->white_sheet = sfRectangleShape_create();
    gui->shadow = sfRectangleShape_create();
    gui->cursor.rect = sfRectangleShape_create();
    gui->cursor.circle = sfCircleShape_create();
    gui_create_custom_size(gui);
}

void gui_create(struct gui *gui, sfRenderWindow *window)
{
    sfVector2f position_white_sheet = {50, 100};
    sfVector2f position_shadow = {35, 115};
    sfColor color_shadow = {210, 216, 236, 255};
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f size_white_sheet = {window_size.x + (1920 - window_size.x) - 220,
                            window_size.y + (1080 - window_size.y) - 200};

    gui_create_variables(gui);
    sfRectangleShape_setSize(gui->white_sheet, size_white_sheet);
    sfRectangleShape_setPosition(gui->white_sheet, position_white_sheet);
    sfRectangleShape_setFillColor(gui->white_sheet, sfWhite);
    sfRectangleShape_setSize(gui->shadow, size_white_sheet);
    sfRectangleShape_setPosition(gui->shadow, position_shadow);
    sfRectangleShape_setFillColor(gui->shadow, color_shadow);
}
