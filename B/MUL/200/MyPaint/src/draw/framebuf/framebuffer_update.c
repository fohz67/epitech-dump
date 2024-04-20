/*
** EPITECH PROJECT, 2022
** framebuffer_update.c
** File description:
** framebuffer_update.c
*/

#include <stdlib.h>
#include "paint.h"

static void framebuffer_rgba(struct gui *gui , int *rgba)
{
    if (my_strcmp(contain_tool_type(gui->cursor.tool), "eraser") == 0) {
        rgba[0] = 255;
        rgba[1] = 255;
        rgba[2] = 255;
        rgba[3] = 255;
    } else {
        rgba[0] = gui->color.r;
        rgba[1] = gui->color.g;
        rgba[2] = gui->color.b;
        rgba[3] = gui->color.a;
    }
}

static void framebuffer_putpixel(struct gui *gui)
{
    int i = 0;
    int rgba[4] = {0, 0, 0, 0};

    framebuffer_rgba(gui, rgba);
    while (i < gui->cursor.tool_radius * 2 *
    gui->cursor.tool_radius * 2 * 4) {
        gui->frame->pixels[i] = rgba[0];
        gui->frame->pixels[i + 1] = rgba[1];
        gui->frame->pixels[i + 2] = rgba[2];
        gui->frame->pixels[i + 3] = rgba[3];
        i += 4;
    }
}

void framebuffer_update(struct gui *gui, sfRenderWindow *window)
{
    sfVector2f sheet_size = sfRectangleShape_getSize(gui->white_sheet);
    sfVector2f sheet_pos = sfRectangleShape_getPosition(gui->white_sheet);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int radius = gui->cursor.tool_radius;
    int decalX = 0;
    int decalY = 0;

    framebuffer_putpixel(gui);
    if (gui->frame->isMoved == true) {
        decalX = sheet_size.x / 2;
        decalY = sheet_size.y / 2;
    }
    sfTexture_updateFromPixels(gui->frame->texture, gui->frame->pixels,
    radius * 2, radius * 2, mouse_pos.x - radius - sheet_pos.x + decalX,
    mouse_pos.y - radius - sheet_pos.y + decalY);
    sfSprite_setTexture(gui->frame->sheet, gui->frame->texture, sfTrue);
}
