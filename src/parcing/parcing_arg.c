/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** parcing_arg
*/

#include <stdio.h>
#include <string.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "struct_flag.h"

static
int check_flag(char *arg, my_sudo_t *my_sudo)
{
    if (strlen(arg) > 2 || strlen(arg) == 1)
        return ERROR_EXIT;
    if (arg[1] == 'h')
        my_sudo->flag = H_FLAG;
    if (arg[1] == 'u')
        my_sudo->flag = U_FLAG;
    if (arg[1] == 'g')
        my_sudo->flag = G_FLAG;
    return SUCCESS_EXIT;
}

int parcing_arg(int ac, char **av, my_sudo_t *my_sudo)
{
    if (ac == 1)
        return ERROR_EXIT;
    for (int i = 1; av[i] != NULL; i++) {
        if (av[i][0] == '-')
            return check_flag(av[i], my_sudo);
    }
    my_sudo->flag = NO_FLAG;
    return SUCCESS_EXIT;
}
