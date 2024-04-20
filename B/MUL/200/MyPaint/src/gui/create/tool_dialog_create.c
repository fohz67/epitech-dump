/*
** EPITECH PROJECT, 2022
** tool_dialog_create.c
** File description:
** tool_dialog_create.c
*/

#include "paint.h"

static void tool_dialog_color(struct gui *gui, int i)
{
    sfColor color_border = {210, 216, 236, 255};
    sfColor color_outline = {150, 156, 176, 255};

    sfRectangleShape_setFillColor(gui->tool[i].dg.rect, sfWhite);
    sfRectangleShape_setFillColor(gui->tool[i].dg.border, color_border);
    sfRectangleShape_setFillColor(gui->tool[i].dg.slider_bg, color_border);
    sfCircleShape_setFillColor(gui->tool[i].dg.slider, sfWhite);
    sfCircleShape_setOutlineColor(gui->tool[i].dg.slider, color_outline);
    sfRectangleShape_setFillColor(gui->tool[i].dg_b.rect, sfWhite);
    sfRectangleShape_setFillColor(gui->tool[i].dg_b.border, color_border);
    sfRectangleShape_setFillColor(gui->tool[i].dg_b.slider_bg, color_border);
    sfCircleShape_setFillColor(gui->tool[i].dg_b.slider, sfWhite);
    sfCircleShape_setOutlineColor(gui->tool[i].dg_b.slider, color_outline);
}

static void tool_dialog_size(struct gui *gui, int i)
{
    sfVector2f size_rect = {350, 100};
    sfVector2f size_border = {355, 110};
    sfVector2f size_slider_bg = {320, 50};

    if (my_strcmp(contain_tool_dialog(i), "color") == 0) {
        size_rect.x = 550; size_border.x = 555; size_slider_bg.x = 510;
    }
    sfRectangleShape_setSize(gui->tool[i].dg.rect, size_rect);
    sfRectangleShape_setSize(gui->tool[i].dg.border, size_border);
    sfRectangleShape_setSize(gui->tool[i].dg.slider_bg, size_slider_bg);
    sfCircleShape_setRadius(gui->tool[i].dg.slider, 25);
    sfCircleShape_setOutlineThickness(gui->tool[i].dg.slider, 5);
    size_rect.x = 305; size_border.x = 315; size_slider_bg.x = 255;
    sfRectangleShape_setSize(gui->tool[i].dg_b.rect, size_rect);
    sfRectangleShape_setSize(gui->tool[i].dg_b.border, size_border);
    sfRectangleShape_setSize(gui->tool[i].dg_b.slider_bg, size_slider_bg);
    sfCircleShape_setRadius(gui->tool[i].dg_b.slider, 25);
    sfCircleShape_setOutlineThickness(gui->tool[i].dg_b.slider, 5);
}

static void tool_dialog_position2(struct gui *gui, int i)
{
    sfVector2f pos_rect = {1225, 220};
    pos_rect.y += i * 120;
    sfVector2f pos_slider_bg = {1250, 245};
    pos_slider_bg.y += i * 120;
    sfVector2f pos_border = {1220, pos_rect.y - 5};

    sfRectangleShape_setTexture(gui->tool[i].dg_b.slider_bg,
    gui->color.black_picker, sfTrue);
    sfRectangleShape_setPosition(gui->tool[i].dg_b.rect, pos_rect);
    sfRectangleShape_setPosition(gui->tool[i].dg_b.border,
    pos_border);
    sfRectangleShape_setPosition(gui->tool[i].dg_b.slider_bg,
    pos_slider_bg);
    pos_slider_bg.x += 20;
    sfCircleShape_setPosition(gui->tool[i].dg_b.slider,
    pos_slider_bg);
}

static void tool_dialog_position(struct gui *gui, int i)
{
    sfVector2f pos_rect = {1425, 100};
    pos_rect.y += i * 120;
    sfVector2f pos_slider_bg = {1450, 125};
    pos_slider_bg.y += i * 120;
    sfVector2f pos_border = {1420, pos_rect.y - 5};

    if (my_strcmp(contain_tool_dialog(i), "color") == 0) {
        pos_rect.x = 1225;
        pos_slider_bg.x = 1250;
        pos_border.x = 1220;
        sfRectangleShape_setTexture(gui->tool[i].dg.slider_bg,
        gui->color.color_picker, sfTrue);
    }
    sfRectangleShape_setPosition(gui->tool[i].dg.rect, pos_rect);
    sfRectangleShape_setPosition(gui->tool[i].dg.border, pos_border);
    sfRectangleShape_setPosition(gui->tool[i].dg.slider_bg, pos_slider_bg);
    if (my_strcmp(contain_tool_dialog(i), "color") != 0) {
        pos_slider_bg.x += 20;
    }
    sfCircleShape_setPosition(gui->tool[i].dg.slider, pos_slider_bg);
}

void tool_dialog_create(struct gui *gui)
{
    int i = 0;

    while (i < TOOLS) {
        gui->tool[i].dg.rect = sfRectangleShape_create();
        gui->tool[i].dg.border = sfRectangleShape_create();
        gui->tool[i].dg.slider = sfCircleShape_create();
        gui->tool[i].dg.slider_bg = sfRectangleShape_create();
        gui->tool[i].dg_b.rect = sfRectangleShape_create();
        gui->tool[i].dg_b.border = sfRectangleShape_create();
        gui->tool[i].dg_b.slider = sfCircleShape_create();
        gui->tool[i].dg_b.slider_bg = sfRectangleShape_create();
        tool_dialog_color(gui, i);
        tool_dialog_size(gui, i);
        tool_dialog_position(gui, i);
        tool_dialog_position2(gui, i);
        i++;
    }
}
