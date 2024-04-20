/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** sign_sigint.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "prompt.h"
#include "scripting.h"

void sigint_handler(int sig)
{
    (void)sig;
    printf("\n");
    simplist_prompt();
}
