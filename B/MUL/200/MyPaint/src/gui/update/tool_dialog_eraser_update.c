/*
** EPITECH PROJECT, 2022
** tool_dialog_eraser_update.c
** File description:
** tool_dialog_eraser_update.c
*/

#include "paint.h"

static void tool_show_eraser_states2(struct gui *gui, int i)
{
    sfColor color_hover = {150, 156, 176, 255};

    sfRectangleShape_setOutlineThickness(
        gui->tool[i].dg_e.button_circle, 0);
    sfRectangleShape_setOutlineThickness(
        gui->tool[i].dg_e.button_rect, 0);
    if (gui->cursor.eraser_type == 2) {
        sfRectangleShape_setOutlineColor(
            gui->tool[i].dg_e.button_circle, color_hover);
        sfRectangleShape_setOutlineThickness(
            gui->tool[i].dg_e.button_circle, 5);
    }
    if (gui->cursor.eraser_type == 1) {
        sfRectangleShape_setOutlineColor(
            gui->tool[i].dg_e.button_rect, color_hover);
        sfRectangleShape_setOutlineThickness(
            gui->tool[i].dg_e.button_rect, 5);
    }
}

void tool_show_eraser_states(struct gui *gui, int i)
{
    sfColor color_hover = {150, 156, 176, 255};
    sfColor color_btn = {210, 216, 236, 255};

    sfRectangleShape_setFillColor(
            gui->tool[i].dg_e.button_circle, color_btn);
    sfRectangleShape_setFillColor(
            gui->tool[i].dg_e.button_rect, color_btn);
    if (gui->tool[i].dg_e.isHover_circle == true
    && gui->cursor.eraser_type == 1) {
        sfRectangleShape_setFillColor(
            gui->tool[i].dg_e.button_circle, color_hover);
            return;
    }
    if (gui->tool[i].dg_e.isHover_rect == true
    && gui->cursor.eraser_type == 2) {
        sfRectangleShape_setFillColor(
            gui->tool[i].dg_e.button_rect, color_hover);
            return;
    }
    tool_show_eraser_states2(gui, i);
}

void tool_show_eraser(struct gui *gui, sfRenderWindow *window, int i)
{
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_e.border, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_e.rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_e.button_circle, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_e.button_rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_e.shape_rect, NULL);
    sfRenderWindow_drawCircleShape(window,
    gui->tool[i].dg_e.shape_circle, NULL);
}
