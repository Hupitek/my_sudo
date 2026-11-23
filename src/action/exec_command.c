/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** exec_command
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "return_macro.h"

int exec_command(int ac, char **av)
{
    char **arg;

    if (ac <= 2)
        return ERROR_EXIT;
    arg = malloc(sizeof(char*) * (ac - 1));
    if (arg == NULL)
        return ERROR_EXIT;
    for (int i = 1; av[i] != NULL; i++)
        arg[i - 1] = av[i];
    arg[ac - 1] = NULL;
    if (arg[0][0] != '-')
        execvp(arg[0], arg);
    free(arg);
    return SUCCESS_EXIT;
}
