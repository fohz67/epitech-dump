/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** My is prime
*/

int my_is_prime(int nb)
{
    int a = 2;

    if (nb < 2)
        return 0;
    while (a < nb) {
        if (nb % a == 0)
            return 0;
        a = a + 1;
    }
    return 1;
}
