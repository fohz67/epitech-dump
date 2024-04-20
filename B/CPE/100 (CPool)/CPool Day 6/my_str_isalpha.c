/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** My str is alpha
*/

void check_alpha(char const *str, int a)
{
    if (str[a] >= 65 && str[a] <= 90 || str[a] >= 97 && str[a] <= 122) {
    } else {
        return 0;
    }
}

int my_str_isalpha(char const *str)
{
    int a = 0;

    if (str[0] != '\0') {
        for (a; str[a] != '\0'; a++) {
            check_alpha(str, a);
        }
        return 1;
    } else {
        return 1;
    }
}
