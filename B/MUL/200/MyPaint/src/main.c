/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include "paint.h"

static sfRenderWindow *window_create(int x, int y, int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};
    return (sfRenderWindow_create(mode, title, sfClose | sfResize, NULL));
}

static void draw_cursor(struct gui *gui, sfRenderWindow *window)
{
    if (gui->cursor.tool == 3 && gui->cursor.eraser_type == 2 &&
        gui->cursor.isOnSheet == true &&
        gui->tool[gui->cursor.tool].dg.isHover != true &&
        gui->tool[gui->cursor.tool].dg_b.isHover != true &&
        gui->tool[gui->cursor.tool].dg_e.isHover != true) {
        sfRenderWindow_drawCircleShape(window, gui->cursor.circle, NULL);
    } else {
        sfRenderWindow_drawRectangleShape(window, gui->cursor.rect, NULL);
    }
}

static int window_loop(struct gui *gui, sfRenderWindow *window)
{
    sfEvent event;
    sfColor color_background = {228, 231, 247, 255};

    sfRenderWindow_setMouseCursorVisible(window, 0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, color_background);
        manage_window(gui, window, event);
        gui_update(gui, window);
        sfRenderWindow_drawSprite(window, gui->frame->sheet, NULL);
        tool_update(gui, window);
        tool_dialog_update(gui, window);
        toolbar_update(gui, window);
        toolbar_dialog_update(gui, window);
        draw_cursor(gui, window);
    }
    return 0;
}

int main(int, const char **, char **env)
{
    if (verif_env(env) == 84 || env[0] == NULL) {
        return 84;
    }
    sfRenderWindow *window = window_create(1920, 1080, 32, LABEL);
    struct gui gui;

    if (malloc_components(&gui) == 84) {
        return 84;
    }
    if (!window || !gui.tool || !gui.toolbar || !gui.frame) {
        return 84;
    }
    if (resources_create(&gui) == 84) {
        return 84;
    }
    create_components(&gui, window);
    window_loop(&gui, window);
    destroy(&gui, window);
    return 0;
}
