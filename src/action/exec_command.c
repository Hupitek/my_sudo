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

// int exec_command(int ac, char **av)
// {
//     char **arg = NULL;

//     if (ac <= 2)
//         return ERROR_EXIT;
//     arg = malloc(sizeof(char*) * (ac - 1));
//     if (arg == NULL)
//         return ERROR_EXIT;
//     for (int i = 1; av[i] != NULL; i++)
//         arg[i - 1] = av[i];
//     arg[ac - 1] = NULL;
//     if (arg[0][0] != '-')
//         execvp(arg[0], arg);
//     free(arg);
//     return SUCCESS_EXIT;
// }

int exec_command(int ac, char **av)
{
    char **arg = NULL;
    int is_sudo = 0;

    if (my_strstr(av[0], "sudo") != NULL && my_strstr(av[0], "_sudo") == NULL)
        is_sudo++;
    if (ac <= is_sudo + 1)
        return ERROR_EXIT;
    arg = malloc(sizeof(char*) * (ac - is_sudo));
    if (arg == NULL)
        return ERROR_EXIT;
    for (int i = is_sudo; av[i] != NULL; i++)
        arg[i - is_sudo] = av[i];
    arg[ac - is_sudo] = NULL;
    if (arg[0][0] != '-')
        execvp(arg[0], arg);
    free(arg);
    return SUCCESS_EXIT;
}
