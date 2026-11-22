/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** free_my_sudo
*/

#include <stdlib.h>
#include "struct_my_sudo.h"

void free_my_sudo(my_sudo_t *my_sudo)
{
    if (my_sudo->hash_algo)
        free(my_sudo->hash_algo);
    if (my_sudo->pwd_input)
        free(my_sudo->pwd_input);
    if (my_sudo->pwd_user)
        free(my_sudo->pwd_user);
    if (my_sudo->salt)
        free(my_sudo->salt);
    if (my_sudo->user)
        free(my_sudo->user);
}
