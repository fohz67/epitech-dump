/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** My str lowcase
*/

char *my_strlowcase(char *str)
{
    int a = 0;
    while (str[a] != '\0') {
        if (str[a] >= 65 && str[a] <= 90)
            str[a] = str[a] + 32;
        a = a + 1;
    }
    return str;
}
