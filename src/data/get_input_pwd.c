/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** get_input_pwd
*/

#include <stdlib.h>
#include <unistd.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int get_pwd_input(my_sudo_t *my_sudo)
{
    char buff[256] = {0};
    int size = 0;

    my_putstr("[sudo: authenticate] Password: ");
    size = read(0, buff, 255);
    my_sudo->pwd_input = malloc(sizeof(char) * (size + 1));
    if (!my_sudo->pwd_input)
        return ERROR_EXIT;
    my_strcpy(my_sudo->pwd_input, buff);
    my_sudo->pwd_input[size - 1] = '\0';
    return SUCCESS_EXIT;
}
