/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_memset.c
*/

int my_memset(char *str, int c, int size)
{
    for (int i = 0; i < size; i++) {
        str[i] = c;
    }
    return 0;
}
