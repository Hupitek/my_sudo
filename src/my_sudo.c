/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** my_sudo
*/

#include "return_macro.h"
#include "struct_my_sudo.h"
#include "func_my_sudo.h"

static
int my_sudo_func(my_sudo_t *my_sudo, int ac, char **av, char **env)
{
    if (get_user(env, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_pwd_input(my_sudo))
        return ERROR_EXIT;
    if (get_shadow_data(my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    hash_pwd(my_sudo);
    if (compare_pwd(my_sudo->pwd_user, my_sudo->pwd_input_hash) == ERROR_EXIT)
        return ERROR_EXIT;
    if (exec_command(ac, av) == ERROR_EXIT)
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
