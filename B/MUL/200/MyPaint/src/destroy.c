/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** destroy.c
*/

#include <stdlib.h>
#include "paint.h"

static void destroy_toobar(struct gui *gui)
{
    int i = 0;
    int j = 0;

    while (i < TOOLBAR) {
        sfRectangleShape_destroy(gui->toolbar[i].rect);
        sfText_destroy(gui->toolbar[i].text);
        while (j < number_item(i)) {
            sfText_destroy(gui->toolbar[i].item[j].text);
            j++;
        }
        free(gui->toolbar[i].item);
        i++;
    }
    free(gui->toolbar);
}

static void destroy_gui(struct gui *gui)
{
    sfRectangleShape_destroy(gui->white_sheet);
    sfRectangleShape_destroy(gui->shadow);
    sfRectangleShape_destroy(gui->cursor.rect);
    sfCircleShape_destroy(gui->cursor.circle);
    sfTexture_destroy(gui->cursor.texture);
    free(gui->cursor.all_radius);
    sfSprite_destroy(gui->frame->sheet);
    sfTexture_destroy(gui->frame->texture);
    free(gui->frame->pixels);
    sfRectangleShape_destroy(gui->text_menu.background);
    sfRectangleShape_destroy(gui->text_menu.box);
    sfRectangleShape_destroy(gui->text_menu.close);
    sfTexture_destroy(gui->text_menu.texture);
    sfTexture_destroy(gui->color.color_picker);
    sfText_destroy(gui->text_menu.title);
    sfText_destroy(gui->text_menu.content);
    sfFont_destroy(gui->font);
}

static void destroy_tools_dialogs(struct gui *gui, int i)
{
    sfRectangleShape_destroy(gui->tool[i].dg_b.border);
    sfRectangleShape_destroy(gui->tool[i].dg_b.rect);
    sfCircleShape_destroy(gui->tool[i].dg_b.slider);
    sfRectangleShape_destroy(gui->tool[i].dg_b.slider_bg);
    sfRectangleShape_destroy(gui->tool[i].dg_e.rect);
    sfRectangleShape_destroy(gui->tool[i].dg_e.border);
    sfRectangleShape_destroy(gui->tool[i].dg_e.button_circle);
    sfRectangleShape_destroy(gui->tool[i].dg_e.button_rect);
    sfRectangleShape_destroy(gui->tool[i].dg_e.shape_rect);
    sfCircleShape_destroy(gui->tool[i].dg_e.shape_circle);
}

static void destroy_tools(struct gui *gui)
{
    int i = 0;

    while (i < TOOLS) {
        sfRectangleShape_destroy(gui->tool[i].rect);
        sfRectangleShape_destroy(gui->tool[i].image);
        sfRectangleShape_destroy(gui->tool[i].shadow);
        sfTexture_destroy(gui->tool[i].texture);
        sfRectangleShape_destroy(gui->tool[i].dg.border);
        sfRectangleShape_destroy(gui->tool[i].dg.rect);
        sfCircleShape_destroy(gui->tool[i].dg.slider);
        sfRectangleShape_destroy(gui->tool[i].dg.slider_bg);
        destroy_tools_dialogs(gui, i);
        i++;
    }
    free(gui->tool);
}

void destroy(struct gui *gui, sfRenderWindow *window)
{
    destroy_tools(gui);
    destroy_toobar(gui);
    destroy_gui(gui);
    sfRenderWindow_destroy(window);
}
