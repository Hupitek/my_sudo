/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** compare_pwd
*/

#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int compare_pwd(my_sudo_t *my_sudo)
{
    if (my_strcmp(my_sudo->pwd_user, my_sudo->pwd_input_hash) != 0)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}
