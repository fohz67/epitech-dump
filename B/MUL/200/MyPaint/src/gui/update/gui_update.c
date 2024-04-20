/*
** EPITECH PROJECT, 2022
** gui_update.c
** File description:
** gui_update.c
*/

#include <stdlib.h>
#include "paint.h"

static void gui_cursor_tool_pencil(struct gui *gui)
{
    sfVector2f origin_tool = {gui->cursor.tool_radius, gui->cursor.tool_radius};
    sfVector2f rect_size = {gui->cursor.tool_radius * 2,
    gui->cursor.tool_radius * 2};

    sfRectangleShape_setSize(gui->cursor.rect, rect_size);
    sfRectangleShape_setFillColor(gui->cursor.rect, sfTransparent);
    sfRectangleShape_setTexture(gui->cursor.rect, NULL, sfTrue);
    sfRectangleShape_setOutlineColor(gui->cursor.rect, sfBlack);
    sfRectangleShape_setOutlineThickness(gui->cursor.rect, 2);
    sfRectangleShape_setOrigin(gui->cursor.rect, origin_tool);
}

static void gui_cursor_tool_eraser(struct gui *gui)
{
    sfVector2f origin_tool = {gui->cursor.tool_radius, gui->cursor.tool_radius};
    sfVector2f rect_size = {gui->cursor.tool_radius * 2,
    gui->cursor.tool_radius * 2};

    sfCircleShape_setRadius(gui->cursor.circle, rect_size.x / 2);
    sfCircleShape_setFillColor(gui->cursor.circle, sfTransparent);
    sfCircleShape_setTexture(gui->cursor.circle, NULL, sfTrue);
    sfCircleShape_setOutlineColor(gui->cursor.circle, sfBlack);
    sfCircleShape_setOutlineThickness(gui->cursor.circle, 2);
    sfCircleShape_setOrigin(gui->cursor.circle, origin_tool);
}

static void gui_cursor_tool_basic(struct gui *gui)
{
    sfVector2f origin_cursor = {MOUSE_DECAL, 0};
    sfVector2f rect_size = {gui->cursor.tool_radius * 2,
    gui->cursor.tool_radius * 2};

    sfRectangleShape_setFillColor(gui->cursor.rect, sfWhite);
    sfRectangleShape_setSize(gui->cursor.rect, rect_size);
    sfRectangleShape_setTexture(gui->cursor.rect, gui->cursor.texture,
    sfTrue);
    sfRectangleShape_setOutlineThickness(gui->cursor.rect, 0);
    sfRectangleShape_setOrigin(gui->cursor.rect, origin_cursor);
}

static void gui_cursor_tool(struct gui *gui)
{
    if (gui->cursor.isOnSheet == true &&
    gui->tool[gui->cursor.tool].dg.isHover != true &&
    gui->tool[gui->cursor.tool].dg_b.isHover != true &&
    gui->tool[gui->cursor.tool].dg_e.isHover != true) {
        gui->cursor.tool_radius = gui->cursor.all_radius[gui->cursor.tool];
        if (my_strcmp(contain_tool_type(gui->cursor.tool), "eraser") == 0 &&
        gui->cursor.eraser_type == 2) {
            gui_cursor_tool_eraser(gui);
            return;
        }
        if ((my_strcmp(contain_tool_type(gui->cursor.tool), "pencil") == 0 ||
        (my_strcmp(contain_tool_type(gui->cursor.tool), "eraser") == 0 &&
        gui->cursor.eraser_type == 1))) {
            gui_cursor_tool_pencil(gui);
            return;
        }
    }
    gui->cursor.tool_radius = gui->cursor.all_radius[0];
    gui_cursor_tool_basic(gui);
}

void gui_update(struct gui *gui, sfRenderWindow *window)
{
    gui_cursor_tool(gui);
    sfRenderWindow_drawRectangleShape(window, gui->shadow, NULL);
    sfRenderWindow_drawRectangleShape(window, gui->white_sheet, NULL);
}
