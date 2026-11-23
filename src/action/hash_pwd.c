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
#include "macro.h"
#include "../../lib/my/include/my.h"

int hash_pwd(my_sudo_t *my_sudo)
{
    char *setting;
    int len_hash_algo = my_strlen(my_sudo->hash_algo);
    int len_salt = my_strlen(my_sudo->salt);

    setting = malloc(sizeof(char) * (len_hash_algo + len_salt + 1));
    if (setting == NULL)
        return ERROR_EXIT;
    my_strcpy(setting, my_sudo->hash_algo);
    my_strcat(setting, my_sudo->salt);
    my_sudo->pwd_input_hash = crypt(my_sudo->pwd_input, setting);
    my_sudo->pwd_input_hash += len_hash_algo + len_salt;
    return SUCCESS_EXIT;
}
