/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec.c
** File description:
** My compute factorial rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return 1;
    if (nb == 1)
        return nb;
    if (nb < 0)
        return 0;
    if (nb >= 13)
        return 0;
    return nb * my_compute_factorial_rec(nb - 1);
}
