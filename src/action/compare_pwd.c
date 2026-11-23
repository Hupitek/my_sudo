/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** compare_pwd
*/

#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int compare_pwd(char *mdp, char *mdp_compare)
{
    if (my_strcmp(mdp, mdp_compare) != 0)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}
