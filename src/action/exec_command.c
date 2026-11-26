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
#include "../../lib/my/include/my.h"
#include "struct_my_sudo.h"

int exec_command(int ac, char **av, my_sudo_t *my_sudo)
{
    char **arg = NULL;
    int indice = 0;

    if (ac <= 1)
        return ERROR_EXIT;
    arg = malloc(sizeof(char*) * (ac));
    if (arg == NULL)
        return ERROR_EXIT;
    for (int i = 1; av[i] != NULL; i++) {
        arg[indice] = av[i];
        indice++;
    }
    arg[indice] = NULL;
    execvp(arg[0], arg);
    return SUCCESS_EXIT;
}