/*
** EPITECH PROJECT, 2022
** manage.c
** File description:
** click.c
*/

#include "paint.h"

void mouse_click(struct gui *gui, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);

    if (gui->text_menu.isShowed == false) {
        tool_click(gui);
        toolbar_click(gui, cursor);
    }
    toolbar_dialog_click(gui, cursor);
}
