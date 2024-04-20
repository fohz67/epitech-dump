/*
** EPITECH PROJECT, 2023
** my_issep.c
** File description:
** my_issep.c
*/

int my_issep(const char c)
{
    if (c == '\0' ||
        c == '\n' ||
        c == '\t' ||
        c == ' ' ||
        c == ':' ||
        c == '=') {
        return 0;
    }
    return 1;
}
