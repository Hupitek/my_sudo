/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** get_user
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int get_user(char **env, my_sudo_t *my_sudo)
{
    int line = 0;
    int indice = 0;

    for (; env[line] != NULL; line++) {
        if (my_strstr(env[line], "SUDO_USER=") != NULL)
            break;
    }
    my_sudo->user = malloc(sizeof(char) * (my_strlen(env[line]) + 1));
    if (my_sudo->user == NULL)
        return ERROR_EXIT;
    for (int i = 10; i < my_strlen(env[line]); i++) {
        my_sudo->user[indice] = env[line][i];
        indice++;
    }
    my_sudo->user[indice] = '\0';
    return SUCCESS_EXIT;
}
