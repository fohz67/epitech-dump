/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** My rev str
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    char c;

    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;

        a = a + 1;
        b = b -1;
    }
    return str;
}
