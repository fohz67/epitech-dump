/*
** EPITECH PROJECT, 2022
** my_str_isupped.c
** File description:
** My str is upper
*/

static void check_isupper(char const *str, int a)
{
    if (str[a] >= 65 && str[a] <= 90) {
    } else {
        return 0;
    }
}

int my_str_isupper(char const *str)
{
    int a = 0;

    if (str[0] != '\0') {
        for (a; str[a] != '\0'; a++) {
            check_isupper(str, a);
        }
        return 1;
    } else {
        return 1;
    }
}
