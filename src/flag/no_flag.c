/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** no_flag
*/

#include <stdio.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "func_my_sudo.h"

int no_flag(int ac, char **av, my_sudo_t *my_sudo)
{
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
