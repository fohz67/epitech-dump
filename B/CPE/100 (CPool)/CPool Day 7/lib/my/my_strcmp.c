/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** My str cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
        a = a + 1;
    return s1[a] - s2[a];
}
