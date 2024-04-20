/*
** EPITECH PROJECT, 2022
** my_show_param_array.c
** File description:
** My show param
*/

int my_show_param_array(struct info_param const *par)
{
    for (int a = 0; par[a] != '\0'; a++) {
        my_putnbr(par[a]->length);
        my_putchar('\n');
        my_putstr(par[a]->str);
        my_putchar('\n');
        my_putstr(par[a]->copy);
        my_putchar('\n');
        my_putstr(par[a]->word_array);
        my_putchar('\n');
    }
    return 0;
}
