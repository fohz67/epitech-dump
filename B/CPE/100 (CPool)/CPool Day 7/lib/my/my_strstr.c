/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** My str str
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] == '\0')
        return NULL;
    for (int a = 0; to_find[a] != '\0'; a++) {
        if (to_find[a] != str[a])
            return my_strstr(str + 1, to_find);
    }
    return str;
}
