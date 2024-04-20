/*
** EPITECH PROJECT, 2022
** toolbar_click.c
** File description:
** toolbar_click.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"

static void toolbar_items(struct gui *gui, int i, int selector)
{
    int j = 0;

    while (j < number_item(i)) {
        if (gui->toolbar[i].item[j].isHover == true) {
            gui->cursor.dg = selector;
            break;
        }
        selector++;
        j++;
    }
}

static void toolbar_unclick_others(struct gui *gui, int i)
{
    int j = 0;

    while (j < TOOLBAR) {
        if (gui->toolbar[j].isClicked == true && i != j) {
            gui->toolbar[j].isClicked = false;
        }
        j++;
    }
}

static int toolbar_click_condition(struct gui *gui, int i, sfVector2i cursor,
int selector)
{
    sfFloatRect fR;
    fR = sfRectangleShape_getGlobalBounds(gui->toolbar[i].rect);

    if (gui->toolbar[i].isHover == true) {
            gui->toolbar[i].isClicked = true;
            return -1;
    }
    if (!sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
        gui->toolbar[i].isClicked = false;
    } else {
        toolbar_items(gui, i, selector);
    }
    return 0;
}

void toolbar_click(struct gui *gui, sfVector2i cursor)
{
    int i = 0;
    int unclick = 0;
    int selector = 0;

    while (i < TOOLBAR) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            unclick = toolbar_click_condition(gui, i, cursor, selector);
        }
        if (unclick == -1) {
            break;
        }
        selector += number_item(i);
        i++;
    }
    if (unclick == -1) {
        toolbar_unclick_others(gui, i);
    }
}
