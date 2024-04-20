/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** my_swap.c
*/

void my_swap(char *s1, char *s2)
{
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
