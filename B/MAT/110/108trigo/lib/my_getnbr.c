/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int my_getnbr(const char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + str[i++] - '0';
        } else {
            return nb;
        }
    }
    return nb;
}
