/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** My str n cpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    for (a; src[a] != '\0' && a < n; a++) {
        dest[a] = src[a];
    }
    if (src[a] == '\0') {
        dest[a] = '\0';
    }
    return dest;
}
