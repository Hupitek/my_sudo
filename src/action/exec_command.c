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

    if (ac <= 2)
        return ERROR_EXIT;
    arg = malloc(sizeof(char*) * (ac - 1));
    if (arg == NULL)
        return ERROR_EXIT;
    for (int i = 1; av[i] != NULL; i++)
        arg[i - 1] = av[i];
    arg[ac - 1] = NULL;
    if (arg[0][0] != '-' && my_sudo->perm == true)
        execvp(arg[0], arg);
    free(arg);
    return SUCCESS_EXIT;
}
