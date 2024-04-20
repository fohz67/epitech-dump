/*
** EPITECH PROJECT, 2022
** components.c
** File description:
** components.c
*/

#include <stdlib.h>
#include "paint.h"

void create_components(struct gui *gui, sfRenderWindow *window)
{
    gui_create(gui, window);
    tool_create(gui);
    tool_dialog_create(gui);
    tool_dialog_eraser_create(gui);
    toolbar_create(gui);
    dialog_create(gui);
    framebuffer_create(gui);
}

int malloc_components(struct gui *gui)
{
    gui->tool = malloc(sizeof(struct tool_st) * TOOLS);
    gui->toolbar = malloc(sizeof(struct toolbar_st) * TOOLBAR);
    gui->frame = malloc((1920 * 1080 * 4) + 1);

    if (gui->tool == NULL || gui->toolbar == NULL || gui->frame == NULL) {
        return 84;
    }
    return 0;
}
