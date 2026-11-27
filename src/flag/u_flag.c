/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** u_flag
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "func_my_sudo.h"

static
int set_user(int ac, char **av, my_sudo_t *my_sudo)
{
    if (ac <= 3)
        return ERROR_EXIT;
    my_sudo->user = malloc(sizeof(char) * (strlen(av[2]) + 1));
    for (int i = 0; av[2][i] != '\0'; i++)
        my_sudo->user[i] = av[2][i];
    my_sudo->user[strlen(av[2])] = '\0';
    return SUCCESS_EXIT;
}

int u_flag(int ac, char **av, my_sudo_t *my_sudo)
{
    if (set_user(ac, av, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_pwd_input(my_sudo))
        return ERROR_EXIT;
    get_sudoers_data(my_sudo);
    if (my_sudo->perm == false)
        return ERROR_EXIT;
    if (get_shadow_data(my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    hash_pwd(my_sudo);
    if (compare_pwd(my_sudo->pwd_user, my_sudo->pwd_input_hash) == ERROR_EXIT) {
        if (incorrect_pwd(my_sudo) == ERROR_EXIT)
            return ERROR_EXIT;
    }
    if (exec_command(ac, av) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}
