/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** My str cpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;
    for (a; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return dest;
}
