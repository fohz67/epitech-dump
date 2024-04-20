/*
** EPITECH PROJECT, 2022
** my_print_revalpha.c
** File description:
** My print revalpha
*/

int my_print_revalpha(void)
{
    char c = 122;

    while (c >= 97) {
        my_putchar(c);
        c--;
    }
    my_putchar('\n');
}
