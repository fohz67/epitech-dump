/*
** EPITECH PROJECT, 2022
** segfault.c
** File description:
** segfault.c
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"

static void print_signal(int termsig)
{
    if (my_strcmp(strsignal(termsig), "Floating point exception") == 0) {
        my_puterror("Floating exception");
    } else {
        my_puterror(strsignal(termsig));
    }
}

int segfault(int status)
{
    int termsig = 0;

    if (WIFSIGNALED(status)) {
        termsig = WTERMSIG(status);
        if (termsig != 0 && termsig != SIGINT) {
            print_signal(termsig);
        }
        if (WCOREDUMP(status)) {
            my_puterror(" (core dumped)\n");
        } else {
            my_puterror("\n");
        }
        return termsig + 128;
    }
    return 0;
}
