/*
** EPITECH PROJECT, 2022
** toolbar_hover.c
** File description:
** toolbar_hover.c
*/

#include <stdbool.h>
#include "paint.h"

static void toolbar_item_hover(struct gui *gui, sfVector2i cursor, int i)
{
    int j = 0;
    sfFloatRect fR;

    while (j < number_item(i)) {
        fR = sfText_getGlobalBounds(gui->toolbar[i].item[j].text);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            gui->toolbar[i].item[j].isHover = true;
        } else {
            gui->toolbar[i].item[j].isHover = false;
        }
        j++;
    }
}

void toolbar_hover(struct gui *gui, sfVector2i cursor)
{
    int i = 0;
    sfFloatRect fR;

    while (i < TOOLBAR) {
        fR = sfText_getGlobalBounds(gui->toolbar[i].text);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            gui->toolbar[i].isHover = true;
        } else {
            gui->toolbar[i].isHover = false;
        }
        fR = sfRectangleShape_getGlobalBounds(gui->toolbar[i].rect);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
        gui->toolbar[i].isClicked == true) {
            gui->cursor.isOnSheet = false;
        }
        toolbar_item_hover(gui, cursor, i);
        i++;
    }
}
