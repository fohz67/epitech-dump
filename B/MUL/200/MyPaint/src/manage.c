/*
** EPITECH PROJECT, 2022
** manage.c
** File description:
** manage.c
*/

#include <stdbool.h>
#include "paint.h"

int verif_env(char **env)
{
    int index = 0;

    while (env[index] != NULL) {
        if (my_strcmp(env[index], "XDG_SESSION_TYPE=tty") == 0) {
            return 84;
        }
        if (my_strncmp(env[index], "DISPLAY", 7) == 0) {
            return 0;
        }
        index++;
    }
    return 0;
}

void manage_black(struct gui *gui, int selector)
{
    selector = my_abs(selector - 255);
    gui->color.b = selector;
    gui->color.r = selector;
    gui->color.g = selector;
}

static void manage_color2(struct gui *gui, int selector)
{
    if (selector <= 340 && selector >= 255) {
        gui->color.g = 255;
        gui->color.r = 0;
        gui->color.b = my_abs(selector - 340) * 3;
        return;
    }
    if (selector <= 425 && selector >= 340) {
        gui->color.g = 255;
        gui->color.b = 0;
        gui->color.r = (selector - 340) * 3;
        return;
    }
    if (selector <= 510 && selector >= 425) {
        gui->color.r = 255;
        gui->color.b = 0;
        gui->color.g = my_abs(selector - 510) * 3;
        return;
    }
}

void manage_color(struct gui *gui, int selector)
{
    if (selector <= 85) {
        gui->color.r = 255;
        gui->color.g = 0;
        gui->color.b = (selector - 0) * 3;
        return;
    }
    if (selector <= 170 && selector >= 85) {
        gui->color.b = 255;
        gui->color.g = 0;
        gui->color.r = my_abs(selector - 170) * 3;
        return;
    }
    if (selector <= 255 && selector >= 170) {
        gui->color.b = 255;
        gui->color.r = 0;
        gui->color.g = (selector - 170) * 3;
        return;
    }
    manage_color2(gui, selector);
}

void manage_window(struct gui *gui, sfRenderWindow *window, sfEvent event)
{
    mouse_hover(gui, window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            mouse_click(gui, window);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        gui->text_menu.isShowed == false) {
            tool_dialog_slider(gui, gui->cursor.tool, window);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        my_strcmp(contain_tool_dialog(gui->cursor.tool), "size") == 0 &&
        gui->cursor.isOnSheet == true && gui->text_menu.isShowed == false &&
        gui->tool[gui->cursor.tool].dg.isHover == false) {
            framebuffer_update(gui, window);
        }
    }
}
