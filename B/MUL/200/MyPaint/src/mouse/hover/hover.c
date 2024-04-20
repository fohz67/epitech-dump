/*
** EPITECH PROJECT, 2022
** hover.c
** File description:
** hover.c
*/

#include <stdbool.h>
#include "paint.h"

static void cursor_sheet(struct gui *gui, sfVector2i cursor)
{
    sfFloatRect fR;

    fR = sfSprite_getGlobalBounds(gui->frame->sheet);
    if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
        gui->cursor.isOnSheet = true;
    } else {
        gui->cursor.isOnSheet = false;
    }
}

static void cursor_move(struct gui *gui, sfVector2i cursor)
{
    sfVector2f cursor_custom = {cursor.x, cursor.y};
    sfRectangleShape_setPosition(gui->cursor.rect, cursor_custom);
    sfCircleShape_setPosition(gui->cursor.circle, cursor_custom);
}

void mouse_hover(struct gui *gui, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);

    cursor_move(gui, cursor);
    if (gui->text_menu.isShowed == false) {
        cursor_sheet(gui, cursor);
        tool_hover(gui, cursor);
        tool_dialog_hover(gui, cursor);
        toolbar_hover(gui, cursor);
    }
}
