/*
** EPITECH PROJECT, 2022
** toolbar_dialog_create.c
** File description:
** toolbar_dialog_create.c
*/

#include <stdlib.h>
#include "paint.h"

static void dialog_text_create(struct gui *gui)
{
    sfColor color_title = {0, 0, 0, 255};
    sfVector2f pos_title = {0, 105};
    sfColor color_content = {0, 0, 0, 255};
    sfVector2f pos_content = {750, 205};
    int title_width = 0;

    sfText_setCharacterSize(gui->text_menu.title, SIZE_FONT_TITLE_MENU);
    sfText_setFont(gui->text_menu.title, gui->font);
    sfText_setColor(gui->text_menu.title, color_title);
    sfText_setString(gui->text_menu.title, "TITRE");
    title_width = sfText_getLocalBounds(gui->text_menu.title).width;
    pos_title.x = 1920 / 2 - title_width / 2;
    sfText_setPosition(gui->text_menu.title, pos_title);
    sfText_setCharacterSize(gui->text_menu.content, SIZE_FONT_CONTENT_MENU);
    sfText_setFont(gui->text_menu.content, gui->font);
    sfText_setColor(gui->text_menu.content, color_content);
    sfText_setString(gui->text_menu.content, "CONTENU");
    sfText_setPosition(gui->text_menu.content, pos_content);
    sfText_setLetterSpacing(gui->text_menu.content, LETTER_SPACING);
}

static void dialog_rect_create(struct gui *gui)
{
    sfVector2f size_bg = {1920, 1080};
    sfColor color_bg = {0, 0, 0, 100};
    sfVector2f pos_bg = {0, 0};
    sfColor color_box = {228, 231, 247, 255};
    sfVector2f pos_box = {710, 75};
    sfVector2f size_close = {30, 30};
    sfColor color_close = {0, 0, 0, 255};
    sfVector2f pos_close = {1160, 100};

    sfRectangleShape_setSize(gui->text_menu.background, size_bg);
    sfRectangleShape_setFillColor(gui->text_menu.background, color_bg);
    sfRectangleShape_setPosition(gui->text_menu.background, pos_bg);
    sfRectangleShape_setFillColor(gui->text_menu.box, color_box);
    sfRectangleShape_setPosition(gui->text_menu.box, pos_box);
    sfRectangleShape_setSize(gui->text_menu.close, size_close);
    sfRectangleShape_setPosition(gui->text_menu.close, pos_close);
    sfRectangleShape_setFillColor(gui->text_menu.close, color_close);
    sfRectangleShape_setTexture(gui->text_menu.close, gui->text_menu.texture,
    sfTrue);
}

void dialog_create(struct gui *gui)
{
    gui->text_menu.background = sfRectangleShape_create();
    gui->text_menu.box = sfRectangleShape_create();
    gui->text_menu.close = sfRectangleShape_create();
    gui->text_menu.content = sfText_create();
    gui->text_menu.title = sfText_create();
    dialog_text_create(gui);
    dialog_rect_create(gui);
}
