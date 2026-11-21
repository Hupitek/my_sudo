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

    for (; env[line] != NULL; line++) {
        if (my_strstr(env[line], "USER=") != NULL)
            break;
    }
    env[line] += 5;
    my_sudo->user = malloc(sizeof(char) * (my_strlen(env[line]) + 1));
    for (int i = 0; i < my_strlen(env[line]); i++)
        my_sudo->user[i] = env[line][i];
    return SUCCESS_EXIT;
}
