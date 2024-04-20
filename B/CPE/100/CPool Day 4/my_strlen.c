/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** My str len
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }

    return (a);
}
