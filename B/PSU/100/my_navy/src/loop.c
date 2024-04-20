/*
** EPITECH PROJECT, 2022
** B-PSU-100-TLS-1-1-navy-benjamin.gayaud
** File description:
** loop.c
*/

#include "../include/my.h"

int read_attack(void)
{
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * 1024);

    read(0, buffer, 1024);
    if (buffer[0] < 'A' ||
        buffer[0] > 'H' ||
        buffer[1] < '1' ||
        buffer[1] > '8') {
        my_putstr("wrong position\n");
        my_putstr("attack: ");
        free(buffer);
        return read_attack();
    }
    write(1, buffer, 2);
    my_putstr(": ETAT\n\n");
    return 0;
}

void turn1(void)
{
    my_putstr("attack: ");
    read_attack();
    kill(my_game.other_pid, SIGUSR1);
    pause();
}

void turn2(void)
{
    my_putstr("waiting for enemy's attack...\n");
    pause();
    kill(my_game.other_pid, SIGUSR1);
    my_putstr("POSITION RECU : ETAT\n\n");
}

void check_print(int total)
{
    if (total % 2 == 0 && total != 0) {
        print_map();
    }
}

void loop(int turn)
{
    int total = 0;

    while (my_game.win == 0) {
        if (turn == 1) {
            check_print(total);
            turn1();
            turn = 2;
            total = total + 1;
        }
        if (turn == 2) {
            check_print(total);
            turn2();
            turn = 1;
            total = total + 1;
        }
    }
}
