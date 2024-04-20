/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** my_swap.c
*/

#include "../include/my.h"

void my_swap(char *strA, char *strB)
{
    char temp = *strA;
    *strA = *strB;
    *strB = temp;
}
