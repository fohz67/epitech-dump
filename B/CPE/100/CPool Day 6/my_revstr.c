/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** My rev str
*/

int my_revlen(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }
    return a;
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_revlen(str) - 1;
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
