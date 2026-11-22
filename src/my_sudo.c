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

int main(int ac, char **av, char **env)
{
    my_sudo_t my_sudo = {0};

    if (get_user(env, &my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_shadow_data(&my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_pwd_input(&my_sudo))
        return ERROR_EXIT;
    hash_pwd(&my_sudo);
    free_my_sudo(&my_sudo);
    return SUCCESS_EXIT;
}
