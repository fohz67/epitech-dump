/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-antman-benjamin.gayaud
** File description:
** my_atoi.c
*/

int my_atoi(char *buffer, int i)
{
    int l_number = 0;

    for (; buffer[i] != ' ' && buffer[i] != '\n'; i++) {
        l_number = l_number * 10;
        l_number = l_number + (buffer[i] - '0');
    }
    return l_number;
}
