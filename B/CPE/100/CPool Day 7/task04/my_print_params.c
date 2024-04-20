/*
** EPITECH PROJECT, 2022
** my_print_params.c
** File description:
** My print params
*/

void my_print_params(int argc, char **argv)
{
    for (int a = 0; a < argc; a++) {
        my_putstr(argv[a]);
        my_putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    my_print_params(argc, argv);
    return (0);
}
