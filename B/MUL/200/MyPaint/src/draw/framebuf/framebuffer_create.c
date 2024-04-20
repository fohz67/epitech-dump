/*
** EPITECH PROJECT, 2022
** framebuffer_create.c
** File description:
** framebuffer_create.c
*/

#include <stdlib.h>
#include "paint.h"

static void framebuffer_elements(struct gui *gui, sfVector2f sheet_size)
{
    sfVector2f sheet_pos = sfRectangleShape_getPosition(gui->white_sheet);

    sfTexture_updateFromPixels(gui->frame->texture, gui->frame->pixels,
    sheet_size.x, sheet_size.y, 0, 0);
    sfSprite_setTexture(gui->frame->sheet, gui->frame->texture, sfTrue);
    sfSprite_setPosition(gui->frame->sheet, sheet_pos);
}

static void framebuffer_values(struct gui *gui, sfVector2f sheet_size)
{
    sfVector2f origin = {0, 0};

    gui->frame->texture = sfTexture_create(sheet_size.x, sheet_size.y);
    gui->frame->sheet = sfSprite_create();
    gui->frame->pixels = NULL;
    gui->frame->pixels = malloc(sheet_size.x * sheet_size.y * 4 + 1);
    sfSprite_setOrigin(gui->frame->sheet, origin);
}

void framebuffer_create(struct gui *gui)
{
    sfVector2f sheet_size = sfRectangleShape_getSize(gui->white_sheet);
    int i = 0;

    framebuffer_values(gui, sheet_size);
    while (i < sheet_size.x * sheet_size.y * 4) {
        gui->frame->pixels[i] = 255;
        gui->frame->pixels[i + 1] = 255;
        gui->frame->pixels[i + 2] = 255;
        gui->frame->pixels[i + 3] = 255;
        i += 4;
    }
    framebuffer_elements(gui, sheet_size);
}
