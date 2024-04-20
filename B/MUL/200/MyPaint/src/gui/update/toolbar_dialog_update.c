/*
** EPITECH PROJECT, 2022
** toolbar_dialog_update.c
** File description:
** toolbar_dialog_update.c
*/

#include <stdlib.h>
#include "paint.h"

void toolbar_dialog_content_update(struct gui *gui, char *title,
char *content)
{
    int title_width = 0;
    sfVector2f pos_title = {0, 120};
    sfVector2f size_box = {500, 0};

    if (my_strcmp(title, ABOUT_TITLE) == 0) {
        size_box.y = ABOUT_SIZE;
    }
    if (my_strcmp(title, HELP_TITLE) == 0) {
        size_box.y = HELP_SIZE;
    }
    sfRectangleShape_setSize(gui->text_menu.box, size_box);
    sfText_setString(gui->text_menu.title, title);
    title_width = sfText_getLocalBounds(gui->text_menu.title).width;
    pos_title.x = 1920 / 2 - title_width / 2;
    sfText_setPosition(gui->text_menu.title, pos_title);
    sfText_setString(gui->text_menu.content, content);
}

void toolbar_dialog_update(struct gui *gui, sfRenderWindow *window)
{
    if (gui->text_menu.isShowed == true) {
        sfRenderWindow_drawRectangleShape(window, gui->text_menu.background,
        NULL);
        sfRenderWindow_drawRectangleShape(window, gui->text_menu.box, NULL);
        sfRenderWindow_drawRectangleShape(window, gui->text_menu.close, NULL);
        sfRenderWindow_drawText(window, gui->text_menu.title, NULL);
        sfRenderWindow_drawText(window, gui->text_menu.content, NULL);
    }
}
