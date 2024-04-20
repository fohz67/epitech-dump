/*
** EPITECH PROJECT, 2022
** mini_putstr.c
** File description:
** Mini putstr
*/

int mini_putchar(char c);

int mini_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        mini_putchar(str[a]);
        a = a + 1;
    }
    return a;
}
