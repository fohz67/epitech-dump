/*
** EPITECH PROJECT, 2022
** my_rev_params.c
** File description:
** My rev params
*/

void my_rev_params(int argc, char **argv)
{
    while (argc-- > 0) {
        my_putstr(argv[argc]);
        my_putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    my_rev_params(argc, argv);
    return (0);
}
