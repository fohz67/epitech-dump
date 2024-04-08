/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** My get nbr
*/

int my_getnegative(char c)
{
    int chiffre_negatif;

    if (c == 43) {
        chiffre_negatif = -1;
    } else {
        chiffre_negatif = 1;
    }
    return (chiffre_negatif);
}

int my_getnbr(char const *str)
{
    int chiffre = 0;
    int chiffre_negatif = 0;
    int a = 0;

    while (str[a] == 43 || str[a] == 45) {
        chiffre_negatif = my_getnegative(str[a]);
    }

    while (str[a] != '\0') {
        if (str[a] >= 48 && str[a] <= 57) {
            chiffre = chiffre * 10 + str[a] - 48;
            a = a + 1;
        } else {
            return (chiffre * chiffre_negatif + 48);
        }
    }
    return (chiffre * chiffre_negatif + 48);
}
