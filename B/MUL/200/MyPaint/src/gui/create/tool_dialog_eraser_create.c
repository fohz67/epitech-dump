/*
** EPITECH PROJECT, 2022
** tool_dialog_eraser_create.c
** File description:
** tool_dialog_eraser_create.c
*/

#include "paint.h"

static void tool_dialog_color(struct gui *gui, int i)
{
    sfColor color_border = {210, 216, 236, 255};
    sfColor color_btn = {210, 216, 236, 200};

    sfRectangleShape_setFillColor(gui->tool[i].dg_e.rect, sfWhite);
    sfRectangleShape_setFillColor(gui->tool[i].dg_e.border, color_border);
    sfRectangleShape_setFillColor(gui->tool[i].dg_e.button_circle, color_btn);
    sfRectangleShape_setFillColor(gui->tool[i].dg_e.button_rect, color_btn);
    sfCircleShape_setFillColor(gui->tool[i].dg_e.shape_circle, sfWhite);
    sfRectangleShape_setFillColor(gui->tool[i].dg_e.shape_rect, sfWhite);
    sfCircleShape_setOutlineColor(gui->tool[i].dg_e.shape_circle, sfBlack);
    sfRectangleShape_setOutlineColor(gui->tool[i].dg_e.shape_rect, sfBlack);
    sfCircleShape_setOutlineThickness(gui->tool[i].dg_e.shape_circle, 2);
    sfRectangleShape_setOutlineThickness(gui->tool[i].dg_e.shape_rect, 2);
}

static void tool_dialog_size(struct gui *gui, int i)
{
    sfVector2f size_rect = {350, 115};
    sfVector2f size_border = {360, 120};
    sfVector2f size_button = {140, 90};
    sfVector2f size_shaperect = {40, 40};

    sfRectangleShape_setSize(gui->tool[i].dg_e.rect, size_rect);
    sfRectangleShape_setSize(gui->tool[i].dg_e.border, size_border);
    sfRectangleShape_setSize(gui->tool[i].dg_e.button_circle, size_button);
    sfRectangleShape_setSize(gui->tool[i].dg_e.button_rect, size_button);
    sfRectangleShape_setSize(gui->tool[i].dg_e.shape_rect, size_shaperect);
    sfCircleShape_setRadius(gui->tool[i].dg_e.shape_circle, 20);
}

static void tool_dialog_position(struct gui *gui, int i)
{
    sfVector2f pos_rect = {1425, 200};
    pos_rect.y += i * 120;
    sfVector2f pos_border = {1420, pos_rect.y};
    sfVector2f pos_button = {1450, 560};
    sfVector2f pos_shape = {1500, 585};

    sfRectangleShape_setPosition(gui->tool[i].dg_e.rect, pos_rect);
    sfRectangleShape_setPosition(gui->tool[i].dg_e.border, pos_border);
    sfRectangleShape_setPosition(gui->tool[i].dg_e.border, pos_border);
    sfRectangleShape_setPosition(gui->tool[i].dg_e.button_rect, pos_button);
    pos_button.x += 160;
    sfRectangleShape_setPosition(gui->tool[i].dg_e.button_circle, pos_button);
    sfRectangleShape_setPosition(gui->tool[i].dg_e.shape_rect, pos_shape);
    pos_shape.x += 160;
    sfCircleShape_setPosition(gui->tool[i].dg_e.shape_circle, pos_shape);
}

void tool_dialog_eraser_create(struct gui *gui)
{
    int i = 0;

    while (i < TOOLS) {
        gui->tool[i].dg_e.rect = sfRectangleShape_create();
        gui->tool[i].dg_e.border = sfRectangleShape_create();
        gui->tool[i].dg_e.button_circle = sfRectangleShape_create();
        gui->tool[i].dg_e.button_rect = sfRectangleShape_create();
        gui->tool[i].dg_e.shape_circle = sfCircleShape_create();
        gui->tool[i].dg_e.shape_rect = sfRectangleShape_create();
        tool_dialog_color(gui, i);
        tool_dialog_size(gui, i);
        tool_dialog_position(gui, i);
        i++;
    }
}
