/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_str_lowercase.c
*/

char *my_str_lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return str;
}
