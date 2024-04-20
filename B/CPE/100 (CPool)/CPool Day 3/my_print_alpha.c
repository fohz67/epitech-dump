/*
** EPITECH PROJECT, 2022
** my_print_alpha.c
** File description:
** My print alpha
*/

int my_print_alpha(void)
{
    char c = 97;

    while (c <= 122) {
        my_putchar(c);
        c++;
    }
    my_putchar('\n');
}
