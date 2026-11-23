/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** get_input_pwd
*/

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int get_pass(my_sudo_t *my_sudo)
{
    char buff[256] = {0};
    int size = 0;

    size = read(0, buff, 255);
    buff[size - 1] = '\0';
    my_sudo->pwd_input = malloc(sizeof(char) * (size + 1));
    if (my_sudo->pwd_input == NULL)
        return ERROR_EXIT;
    my_strcpy(my_sudo->pwd_input, buff);
    my_putchar('\n');
    return SUCCESS_EXIT;
}

int get_pwd_input(my_sudo_t *my_sudo)
{
    struct termios new;
    struct termios old;

    my_putstr("[my_sudo: authenticate] Password: ");
    if (tcgetattr(STDIN_FILENO, &old) != 0)
        return ERROR_EXIT;
    new = old;
    new.c_lflag &= ~ECHO;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &new) != 0)
        return ERROR_EXIT;
    if (get_pass(my_sudo) == ERROR_EXIT) {
        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &old) != 0)
            return ERROR_EXIT;
        return ERROR_EXIT;
    }
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &old) != 0)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}
