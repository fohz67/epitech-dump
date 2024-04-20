/*
** EPITECH PROJECT, 2022
** my_print_digits.c
** File description:
** My print digits
*/

int my_print_digits(void)
{
    int i;

    for (i = 0; i <= 9; i++) {
        my_putchar(48 + i);
    }

    my_putchar('\n');
}
