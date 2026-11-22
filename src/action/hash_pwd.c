/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** hash_pwd
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <crypt.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int hash_pwd(my_sudo_t *my_sudo)
{
    my_sudo->pwd_input_hash = crypt(my_sudo->pwd_input, my_sudo->salt + 1);
    printf("mdp user: %s\n", my_sudo->pwd_user);
    return SUCCESS_EXIT;
}
