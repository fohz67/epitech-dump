/*
** EPITECH PROJECT, 2022
** toolbar_dialog_click.c
** File description:
** toolbar_dialog_click.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"

void toolbar_dialog_click(struct gui *gui, sfVector2i cursor)
{
    sfFloatRect fR;

    fR = sfRectangleShape_getGlobalBounds(gui->text_menu.close);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
        gui->text_menu.isShowed = false;
    }
}
