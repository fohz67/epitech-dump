/*
** EPITECH PROJECT, 2022
** tool_hover.c
** File description:
** tool_hover.c
*/

#include <stdbool.h>
#include "paint.h"

static void tool_dialog_eraser2_hover(struct gui *gui, sfVector2i cursor,
int i)
{
    sfFloatRect fR;

    fR = sfRectangleShape_getGlobalBounds(
        gui->tool[i].dg_e.button_rect);
    if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
        gui->tool[i].isRClicked == true && i == 3) {
        gui->tool[i].dg_e.isHover_rect = true;
    } else {
        gui->tool[i].dg_e.isHover_rect = false;
    }
}

static void tool_dialog_eraser_hover(struct gui *gui, sfVector2i cursor,
int i)
{
    sfFloatRect fR;
    sfFloatRect fR2;

    fR = sfRectangleShape_getGlobalBounds(
        gui->tool[i].dg_e.border);
    fR2 = sfRectangleShape_getGlobalBounds(
        gui->tool[i].dg_e.button_circle);
    if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
        gui->tool[i].isRClicked == true && i == 3) {
        gui->tool[i].dg_e.isHover = true;
    } else
        gui->tool[i].dg_e.isHover = false;
    if (sfFloatRect_contains(&fR2, cursor.x, cursor.y) &&
        gui->tool[i].isRClicked == true && i == 3) {
        gui->tool[i].dg_e.isHover_circle = true;
    } else
        gui->tool[i].dg_e.isHover_circle = false;
    tool_dialog_eraser2_hover(gui, cursor, i);
}

void tool_dialog_hover(struct gui *gui, sfVector2i cursor)
{
    int i = 0;
    sfFloatRect fR;
    sfFloatRect fR2;

    while (i < TOOLS) {
        fR = sfRectangleShape_getGlobalBounds(gui->tool[i].dg.border);
        fR2 = sfRectangleShape_getGlobalBounds(gui->tool[i].dg_b.border);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
        gui->tool[i].isRClicked == true)
            gui->tool[i].dg.isHover = true;
        else
            gui->tool[i].dg.isHover = false;
        if (sfFloatRect_contains(&fR2, cursor.x, cursor.y) &&
        gui->tool[i].isRClicked == true && i == 2)
            gui->tool[i].dg_b.isHover = true;
        else
            gui->tool[i].dg_b.isHover = false;
        tool_dialog_eraser_hover(gui, cursor, i);
        i++;
    }
}

void tool_hover(struct gui *gui, sfVector2i cursor)
{
    int i = 0;
    sfFloatRect fR;

    while (i < TOOLS) {
        fR = sfRectangleShape_getGlobalBounds(gui->tool[i].rect);
        if (sfFloatRect_contains(&fR, cursor.x, cursor.y)) {
            gui->tool[i].isHover = true;
        } else {
            gui->tool[i].isHover = false;
        }
        i++;
    }
}
