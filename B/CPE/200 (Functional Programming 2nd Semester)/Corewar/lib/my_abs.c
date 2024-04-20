/*
** EPITECH PROJECT, 2023
** my_abs.c
** File description:
** my_abs.c
*/

float my_abs(float nb)
{
    if (nb < 0) {
        nb = nb * -1;
    }
    return nb;
}
