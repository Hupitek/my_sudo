/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** my_sudo
*/

#include <stdio.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "func_my_sudo.h"
#include "struct_flag.h"

flag_t const tab[] = {
    {&no_flag, NO_FLAG}
};

static
int my_sudo_func(my_sudo_t *my_sudo, int ac, char **av, char **env)
{
    parcing_arg(ac, av, my_sudo);
    if (my_sudo->flag == H_FLAG)
        return h_flag(ac, av);
    if (tab[my_sudo->flag].func(ac, av, env, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

int main(int ac, char **av, char **env)
{
    my_sudo_t my_sudo = {0};

    init_my_sudo(&my_sudo);
    if (my_sudo_func(&my_sudo, ac, av, env) == ERROR_EXIT) {
        free_my_sudo(&my_sudo);
        return ERROR_EXIT;
    }
    return SUCCESS_EXIT;
}
