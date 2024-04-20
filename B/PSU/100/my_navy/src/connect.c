/*
** EPITECH PROJECT, 2022
** connect.c
** File description:
** connect.c
*/

#include "../include/my.h"

void get_other_pid(int signum, siginfo_t *other_info, void *oldact)
{
    my_game.other_pid = other_info->si_pid;
}

void base_id(struct sigaction *sig)
{
    sig->sa_flags = SA_SIGINFO;
    sig->sa_sigaction = get_other_pid;
    my_putstr("my_pid: ");
    my_putnbr(getpid());
}

int first_id(struct sigaction *sig)
{
    my_putstr("\nwaiting for enemy connection...\n");
    sigaction(SIGUSR1, sig, NULL);
    pause();
    kill(my_game.other_pid, SIGUSR1);
    my_putstr("\nenemy connected\n\n");
    print_map();
    loop(1);
    return 0;
}

int second_id(struct sigaction *sig, const char **av)
{
    my_game.other_pid = my_getnbr(av[1]);
    kill(my_game.other_pid, SIGUSR1);
    sigaction(SIGUSR1, sig, NULL);
    pause();
    my_putstr("\nsuccessfully connected\n\n");
    print_map();
    loop(2);
    return 0;
}

void sent_signal(char *buffer)
{
    int letter = 0;
    int number = 0;

    letter = buffer[0] - 64;
    number = buffer[1] - 48;

    while (letter > 0) {
        kill(my_game.other_pid, SIGUSR1);
        letter--;
        pause();
    }
    kill(my_game.other_pid, SIGUSR2);
    pause();
    while (number > 0) {
        kill(my_game.other_pid, SIGUSR1);
        number--;
        pause();
    }
    kill(my_game.other_pid, SIGUSR2);
}
