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

int get_user_line(int *line, char **env)
{
    int a = 0;

    for (; env[*line] != NULL; *line += 1) {
        if (my_strstr(env[*line], "USER=") != NULL)
            break;
    }
    if (env[*line] == NULL)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

int get_user(char **env, my_sudo_t *my_sudo)
{
    int line = 0;
    int indice = 0;
    int can_write = 0;

    if (get_user_line(&line, env) == ERROR_EXIT)
        return ERROR_EXIT;
    my_sudo->user = malloc(sizeof(char) * (my_strlen(env[line]) + 1));
    if (my_sudo->user == NULL)
        return ERROR_EXIT;
    for (int i = 0; i < my_strlen(env[line]); i++) {
        if (can_write == 1) {
            my_sudo->user[indice] = env[line][i];
            indice++;
        }
        if (env[line][i] == '=')
            can_write++;
    }
    my_sudo->user[indice] = '\0';
    return SUCCESS_EXIT;
}
