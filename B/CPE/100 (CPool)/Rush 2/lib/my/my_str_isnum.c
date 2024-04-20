/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** My str is num
*/

static void check_number(char const *str, int a)
{
    if (str[a] >= 48 && str[a] <= 59) {
    } else {
        return 0;
    }
}

int my_str_isnum(char const *str)
{
    int a = 0;

    if (str[0] != '\0') {
        for (a; str[a] != '\0'; a++) {
            check_number(str, a);
        }
        return 1;
    } else {
        return 1;
    }
}
