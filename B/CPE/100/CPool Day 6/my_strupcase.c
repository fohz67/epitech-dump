/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** My str upcase
*/

char *my_strupcase(char *str)
{
    int a = 0;
    while (str[a] != '\0') {
        if (str[a] >= 97 && str[a] <= 122) {
            str[a] = str[a] - 32;
        }
        a = a + 1;
    }
    return str;
}
