/*
** EPITECH PROJECT, 2022
** my_evil_str.c
** File description:
** My evil str
*/

int my_strlen_bis(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}

char *my_evil_str(char *str)
{
    int a = 0;
    int b = my_strlen_bis(str) - 1;
    char c;

    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;

        a = a + 1;
        b = b -1;

    }

    return (str);
}
