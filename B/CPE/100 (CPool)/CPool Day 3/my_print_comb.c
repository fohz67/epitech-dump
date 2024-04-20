/*
** EPITECH PROJECT, 2022
** my_print_comb.c
** File description:
** My print comb
*/

int last_number(int a, int b, int c)
{
    if (a == 7 && b == 8 && c == 9) {
        my_putchar('\n');
    } else {
        my_putchar(44);
        my_putchar(32);
    }

}

int last_for(int a, int b, int c)
{
    for (c = b + 1 ; c <= 9 ; c ++) {
        my_putchar(48 + a);
        my_putchar(48 + b);
        my_putchar(48 + c);
        last_number(a, b, c);
    }
}

int my_print_comb(void)
{
    int a, b, c;

    for (a = 0 ; a <= 7 ; a++) {
        for (b = a + 1 ; b <= 8 ; b++) {
            last_for(a, b, c);
        }
    }
}
