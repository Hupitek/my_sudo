/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** exec_user_command
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "return_macro.h"

int exec_user_command(int ac, char **av)
{
    char **arg = NULL;
    int indice = 0;

    arg = malloc(sizeof(char*) * (ac - 2));
    if (arg == NULL)
        return ERROR_EXIT;
    for (int i = 3; av[i] != NULL; i++) {
        arg[indice] = av[i];
        indice++;
    }
    arg[indice] = NULL;
    execvp(arg[0], arg);
    return SUCCESS_EXIT;
}
