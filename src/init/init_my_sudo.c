/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** init_my_sudo
*/

#include <stdlib.h>
#include "struct_my_sudo.h"

void init_my_sudo(my_sudo_t *my_sudo)
{
    my_sudo->hash_algo = NULL;
    my_sudo->perm = true;
    my_sudo->pwd_input = NULL;
    my_sudo->pwd_input_hash = NULL;
    my_sudo->pwd_user = NULL;
    my_sudo->salt = NULL;
    my_sudo->user = NULL;
}
