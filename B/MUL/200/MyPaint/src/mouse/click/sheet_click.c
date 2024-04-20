/*
** EPITECH PROJECT, 2022
** sheet_click.c
** File description:
** sheet_click.c
*/

#include "paint.h"

void sheet_click(struct gui *gui, sfRenderWindow *window)
{
    sfVector2f size_sheet = sfRectangleShape_getSize(gui->white_sheet);

    if (gui->cursor.isOnSheet == true && gui->cursor.tool == 0) {
        sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
        sfVector2f diff_pos = {size_sheet.x / 2, size_sheet.y / 2};
        sfVector2f final_cursor = {cursor.x, cursor.y};
        sfVector2f final_cursor_shadow = {cursor.x - 20, cursor.y + 20};
        sfRectangleShape_setOrigin(gui->white_sheet, diff_pos);
        sfRectangleShape_setOrigin(gui->shadow, diff_pos);
        sfSprite_setOrigin(gui->frame->sheet, diff_pos);
        sfRectangleShape_setPosition(gui->white_sheet, final_cursor);
        sfRectangleShape_setPosition(gui->shadow, final_cursor_shadow);
        sfSprite_setPosition(gui->frame->sheet, final_cursor);
        gui->frame->isMoved = true;
    }
}
