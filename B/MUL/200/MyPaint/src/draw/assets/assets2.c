/*
** EPITECH PROJECT, 2022
** assets2.c
** File description:
** assets2.c
*/

#include "paint.h"

static char *var_contain_tool_type[] = {
    "cursor", "pencil", "color", "eraser",
};

char *contain_tool_type(int i)
{
    return var_contain_tool_type[i];
}
