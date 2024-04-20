/*
** EPITECH PROJECT, 2022
** tool_dialog_update.c
** File description:
** tool_dialog_update.c
*/

#include "paint.h"

static void tool_show_color(struct gui *gui, sfRenderWindow *window, int i)
{
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_b.border, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_b.rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
    gui->tool[i].dg_b.slider_bg, NULL);
    sfRenderWindow_drawCircleShape(window,
    gui->tool[i].dg_b.slider, NULL);
}

static void tool_show_nocolor(struct gui *gui, sfRenderWindow *window, int i)
{
    sfRenderWindow_drawRectangleShape(window, gui->tool[i].dg.border,
    NULL);
    sfRenderWindow_drawRectangleShape(window, gui->tool[i].dg.rect,
    NULL);
    sfRenderWindow_drawRectangleShape(window, gui->tool[i].dg.slider_bg,
    NULL);
    sfRenderWindow_drawCircleShape(window, gui->tool[i].dg.slider,
    NULL);
}

void tool_dialog_update(struct gui *gui, sfRenderWindow *window)
{
    int i = 0;

    while (i < TOOLS) {
        if (my_strcmp(contain_tool_dialog(i), "null") != 0 &&
        gui->tool[i].isRClicked == true) {
            tool_show_nocolor(gui, window, i);
        }
        if (my_strcmp(contain_tool_dialog(i), "color") == 0 &&
        gui->tool[i].isRClicked == true) {
            tool_show_color(gui, window, i);
        }
        if (my_strcmp(contain_tool_type(i), "eraser") == 0 &&
        gui->tool[i].isRClicked == true) {
            tool_show_eraser_states(gui, i);
            tool_show_eraser(gui, window, i);
        }
        i++;
    }
}
