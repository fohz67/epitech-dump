/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** My swap
*/

void my_swap(int *a, int *b)
{
    int a_bis = *a;
    int b_bis = *b;

    *a = b_bis;
    *b = a_bis;
}
