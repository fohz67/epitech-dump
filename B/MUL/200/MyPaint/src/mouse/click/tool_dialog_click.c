/*
** EPITECH PROJECT, 2022
** tool_dialog_click.c
** File description:
** tool_dialog_click.c
*/

#include <stdbool.h>
#include "paint.h"

static void tool_dialog_size_slider(struct gui *gui, sfFloatRect fR, int i,
sfVector2i cursor)
{
    sfVector2f pos_slider = sfCircleShape_getPosition(
        gui->tool[i].dg.slider);
    sfVector2f pos_bg = sfRectangleShape_getPosition(
        gui->tool[i].dg.slider_bg);

    pos_slider.x = cursor.x - MOUSE_DECAL;
    if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
    gui->tool[i].dg.isHover == true && pos_slider.x > pos_bg.x &&
    pos_slider.x + 50 < pos_bg.x + 320) {
        gui->cursor.all_radius[i] = pos_slider.x - pos_bg.x + 1;
        sfCircleShape_setPosition(gui->tool[i].dg.slider, pos_slider);
    }
}

static void tool_dialog_black_slider(struct gui *gui, sfFloatRect fR, int i,
sfVector2i cursor)
{
    sfVector2f pos_slider = sfCircleShape_getPosition(
        gui->tool[i].dg_b.slider);
    sfVector2f pos_bg = sfRectangleShape_getPosition(
        gui->tool[i].dg_b.slider_bg);

    pos_slider.x = cursor.x - MOUSE_DECAL;

    if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
    gui->tool[i].dg_b.isHover == true && pos_slider.x > pos_bg.x &&
    pos_slider.x + 50 < pos_bg.x + 510) {
        manage_black(gui, pos_slider.x - pos_bg.x + 1);
        sfCircleShape_setPosition(gui->tool[i].dg_b.slider, pos_slider);
    }
}

static void tool_dialog_color_slider(struct gui *gui, sfFloatRect fR, int i,
sfVector2i cursor)
{
    sfVector2f pos_slider = sfCircleShape_getPosition(
        gui->tool[i].dg.slider);
    sfVector2f pos_bg = sfRectangleShape_getPosition(
        gui->tool[i].dg.slider_bg);

    pos_slider.x = cursor.x - MOUSE_DECAL;

    if (sfFloatRect_contains(&fR, cursor.x, cursor.y) &&
    gui->tool[i].dg.isHover == true && pos_slider.x > pos_bg.x &&
    pos_slider.x + 50 < pos_bg.x + 510) {
        manage_color(gui, pos_slider.x - pos_bg.x + 1);
        sfCircleShape_setPosition(gui->tool[i].dg.slider, pos_slider);
    }
}

void tool_dialog_slider(struct gui *gui, int i, sfRenderWindow *window)
{
    sfFloatRect fR;
    sfFloatRect fR2;
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);

    fR = sfRectangleShape_getGlobalBounds(gui->tool[i].dg.slider_bg);
    fR2 = sfRectangleShape_getGlobalBounds(
        gui->tool[i].dg_b.slider_bg);

    if (my_strcmp(contain_tool_dialog(i), "color") == 0) {
        tool_dialog_color_slider(gui, fR, i, cursor);
        tool_dialog_black_slider(gui, fR2, i, cursor);
    }
    if (my_strcmp(contain_tool_dialog(i), "size") == 0) {
        tool_dialog_size_slider(gui, fR, i, cursor);
    }
}
