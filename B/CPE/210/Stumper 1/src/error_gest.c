/*
** EPITECH PROJECT, 2023
** Fractals
** File description:
** DuoStumper1
*/

static int check_arg3(const char *av3)
{
    for (int i = 0; av3[i] != '\0'; i++) {
        if (av3[i] != '.' && av3[i] != '@') {
            return 84;
        }
    }
    return 0;
}

static int check_arg2(const char *av2)
{
    for (int i = 0; av2[i] != '\0'; i++) {
        if (av2[i] != '#' && av2[i] != '.' && av2[i] != '@') {
            return 84;
        }
    }
    return 0;
}

static int check_arg1_verif(const char *av1, int i)
{
    char nbr[] = "0123456789";

    for (int check = 0; nbr[check] != '\0'; check++) {
        if (av1[i] == nbr[check]) {
            return 1;
        }
    }
    return 0;
}

static int check_arg1(const char *av1)
{
    for (int i = 0; av1[i] != '\0'; i++) {
        if (check_arg1_verif(av1, i) == 0) {
            return 84;
        }
    }
    return 0;
}

int error_gestion(int ac, const char **av)
{
    if (ac != 4) {
        return 84;
    }
    if (check_arg1(av[1]) == 84) {
        return 84;
    }
    if (check_arg2(av[2]) == 84) {
        return 84;
    }
    if (check_arg3(av[3]) == 84) {
        return 84;
    }
    return 0;
}
