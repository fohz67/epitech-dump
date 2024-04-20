/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** My str n cmp
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int	a = 0;

    while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0' && a < n) {
        a = a +	1;
    }
    return s1[a] - s2[a];
}
