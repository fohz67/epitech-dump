/*
** EPITECH PROJECT, 2022
** tool_click.c
** File description:
** tool_click.c
*/

#include <stdbool.h>
#include "paint.h"

void tool_unclick(struct gui *gui, int i)
{
    int j = 0;

    while (j < TOOLS) {
        if (i == j) {
            gui->tool[j].isLClicked = true;
        }
        if (gui->tool[j].isLClicked == true && i != j) {
            gui->tool[j].isLClicked = false;
        }
        if (gui->tool[j].isRClicked == true && i != j) {
            gui->tool[j].isRClicked = false;
        }
        j++;
    }
}

static int tool_eraser_contain_click(struct gui *gui, int i)
{
    if (gui->tool[i].dg_e.isHover_rect == true) {
        gui->cursor.eraser_type = 1;
        return 0;
    }
    if (gui->tool[i].dg_e.isHover_circle == true) {
        gui->cursor.eraser_type = 2;
        return 0;
    }
    return 0;
}

static int tool_contain_click(struct gui *gui, int i)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) &&
    my_strcmp(contain_tool_dialog(i), "color") != 0) ||
    (sfMouse_isButtonPressed(sfMouseLeft) &&
    my_strcmp(contain_tool_dialog(i), "color") == 0 &&
        gui->tool[i].isRClicked == true)) {
        gui->tool[i].isLClicked = true;
        gui->tool[i].isRClicked = false;
        gui->cursor.tool = i;
        return -1;
    }
    if (sfMouse_isButtonPressed(sfMouseRight) ||
    my_strcmp(contain_tool_dialog(i), "color") == 0) {
        gui->tool[i].isRClicked = true;
        gui->cursor.tool = i;
        return -1;
    }
    return 0;
}

static int tool_condition_click(struct gui *gui, int i)
{
    int unclick = 0;

    if (gui->tool[i].isHover == true) {
        if (tool_contain_click(gui, i) == -1)
            return -1;
    } else {
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        gui->tool[i].isRClicked == true &&
        gui->tool[i].dg.isHover == false &&
        gui->tool[i].dg_b.isHover == false) {
            unclick = 0;
            gui->tool[i].isLClicked = true;
            gui->cursor.tool = i;
            gui->tool[i].isRClicked = false;
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            my_strcmp(contain_tool_type(i), "eraser") == 0)
                return tool_eraser_contain_click(gui, i);
    }
    return unclick;
}

void tool_click(struct gui *gui)
{
    int i = 0;
    int unclick = 0;

    while (i < TOOLS) {
        unclick = tool_condition_click(gui, i);
        if (unclick == -1) {
            break;
        }
        i++;
    }
    if (unclick == -1) {
        tool_unclick(gui, i);
    }
}
