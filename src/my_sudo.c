/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** my_sudo
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "macro.h"
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../lib/my/include/my.h"
#include "func_my_sudo.h"

int check_arg(int ac, char **av)
{
    char **arg;

    if (ac <= 2)
        return ERROR_EXIT;
    arg = malloc(sizeof(char*) * (ac - 1));
    if (!arg)
        return ERROR_EXIT;
    for (int i = 1; av[i] != NULL; i++)
        arg[i - 1] = av[i];
    arg[ac - 1] = NULL;
    if (arg[0][0] != '-')
        execvp(arg[0], arg);
    free(arg);
    return SUCCESS_EXIT;
}

int my_sudo_func(my_sudo_t *my_sudo, int ac, char **av, char **env)
{
    if (get_user(env, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_shadow_data(my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_pwd_input(my_sudo))
        return ERROR_EXIT;
    hash_pwd(my_sudo);
    if (compare_pwd(my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (check_arg(ac, av) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

int main(int ac, char **av, char **env)
{
    my_sudo_t my_sudo = {0};

    if (my_sudo_func(&my_sudo, ac, av, env) == ERROR_EXIT) {
        free_my_sudo(&my_sudo);
        return ERROR_EXIT;
    }
    return SUCCESS_EXIT;
}
