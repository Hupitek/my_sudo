/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** incorrect_pwd
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "func_my_sudo.h"

int incorrect_pwd(my_sudo_t *my_sudo)
{
    for (int i = 0; i < 2; i++) {
        sleep(3);
        printf("my_sudo: Authentication failed, try again.\n");
        free(my_sudo->pwd_input);
        get_pwd_input(my_sudo);
        hash_pwd(my_sudo);
        if (compare_pwd(my_sudo->pwd_user, my_sudo->pwd_input_hash) == 0)
            return SUCCESS_EXIT;
    }
    sleep(3);
    printf("my_sudo: maximum 3 incorrect authentication attempts\n");
    return ERROR_EXIT;
}
