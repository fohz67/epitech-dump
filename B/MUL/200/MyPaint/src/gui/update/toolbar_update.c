/*
** EPITECH PROJECT, 2022
** toolbar_update.c
** File description:
** toolbar_update.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"

static void toolbar_item_clicked3(struct gui *gui, int i, int j)
{
    if (gui->cursor.dg == 5){
        gui->text_menu.isShowed = true;
        gui->cursor.dg = -1;
        gui->toolbar[i].item[j].isHover = false;
        gui->toolbar[i].isClicked = false;
        gui->toolbar[i].isHover = false;
        toolbar_dialog_content_update(gui, ABOUT_TITLE, ABOUT_CONTENT);
    }
    if (gui->cursor.dg == 6){
        gui->text_menu.isShowed = true;
        gui->cursor.dg = -1;
        gui->toolbar[i].item[j].isHover = false;
        gui->toolbar[i].isClicked = false;
        gui->toolbar[i].isHover = false;
        toolbar_dialog_content_update(gui, HELP_TITLE, HELP_CONTENT);
    }
}

static void toolbar_item_clicked2(struct gui *gui, int i, int j)
{
    if (gui->cursor.dg == 3){
        gui->cursor.tool = 1;
        gui->cursor.dg = -1;
        gui->toolbar[i].item[j].isHover = false;
        gui->toolbar[i].isClicked = false;
        gui->toolbar[i].isHover = false;
        tool_unclick(gui, gui->cursor.tool);
    }
    if (gui->cursor.dg == 4){
        gui->cursor.tool = 3;
        gui->cursor.dg = -1;
        gui->toolbar[i].item[j].isHover = false;
        gui->toolbar[i].isClicked = false;
        gui->toolbar[i].isHover = false;
        tool_unclick(gui, gui->cursor.tool);
    }
    toolbar_item_clicked3(gui, i, j);
}

static void toolbar_item_clicked(struct gui *gui, int i, int j)
{
    if (gui->cursor.dg == 0){
        gui->cursor.dg = -1;
        gui->toolbar[i].item[j].isHover = false;
        gui->toolbar[i].isClicked = false;
        gui->toolbar[i].isHover = false;
        if (!(!gui->frame->pixels || gui->frame->pixels == NULL)) {
            framebuffer_create(gui);
        }
    }
    if (gui->cursor.dg == 1){
    }
    if (gui->cursor.dg == 2){
        sfImage_saveToFile(sfTexture_copyToImage(gui->frame->texture),
        "image.jpg");
    }
    toolbar_item_clicked2(gui, i, j);
}

static void toolbar_item(struct gui *gui, sfRenderWindow *window, int i)
{
    sfColor color_text_hover = {210, 216, 236, 255};
    int j = 0;
    int selector = 0;

    sfRenderWindow_drawRectangleShape(window, gui->toolbar[i].rect, NULL);
    while (j < number_item(i)) {
        if (gui->toolbar[i].item[j].isHover == true) {
            sfText_setFillColor(gui->toolbar[i].item[j].text,
            color_text_hover);
        } else {
            sfText_setFillColor(gui->toolbar[i].item[j].text, sfWhite);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            toolbar_item_clicked(gui, i, j);
        }
        sfRenderWindow_drawText(window, gui->toolbar[i].item[j].text, NULL);
        selector += number_item(i);
        j++;
    }
}

void toolbar_update(struct gui *gui, sfRenderWindow *window)
{
    int i = 0;
    sfColor color_text = {147, 148, 174, 255};
    sfColor color_text_hover = {177, 178, 203, 255};

    while (i < TOOLBAR) {
        if (gui->toolbar[i].isClicked == true) {
            toolbar_item(gui, window, i);
            sfText_setFillColor(gui->toolbar[i].text, color_text_hover);
        }
        if (gui->toolbar[i].isHover == true) {
            sfText_setFillColor(gui->toolbar[i].text, color_text_hover);
        }
        if (gui->toolbar[i].isHover != true &&
        gui->toolbar[i].isClicked != true) {
            sfText_setFillColor(gui->toolbar[i].text, color_text);
        }
        sfRenderWindow_drawText(window, gui->toolbar[i].text, NULL);
        i++;
    }
}
