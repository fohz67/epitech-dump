/*
** EPITECH PROJECT, 2022
** my_issep.c
** File description:
** my_issep.c
*/

int my_issep(const char c)
{
    if (c == '\0' ||
        c == '*') {
        return 0;
    }
    return 1;
}
