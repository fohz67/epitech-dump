/*
** EPITECH PROJECT, 2022
** assets.c
** File description:
** assets.c
*/

#include "paint.h"

static char *var_name_toolbar[] = {
    "File", "Edit", "Help", "SboobyDoo", "Velma"
};

static char *var_name_item[] = {
    "New file", "Open file", "Save file",
    "Pencil", "Eraser",
    "About", "Help"
};

static int var_number_item[] = {
    3, 2, 2
};

static char *var_textures[] = {
    "textures/cursor.png", "textures/pencil.png", "textures/palette.png",
    "textures/eraser.png"
};

static char *var_contain_tool_dialog[] = {
    "null", "size", "color", "size",
};

char *name_toolbar(int i)
{
    return var_name_toolbar[i];
}

char *name_item(int i)
{
    return var_name_item[i];
}

int number_item(int i)
{
    return var_number_item[i];
}

char *texture_tool(int i)
{
    return var_textures[i];
}

char *contain_tool_dialog(int i)
{
    return var_contain_tool_dialog[i];
}
