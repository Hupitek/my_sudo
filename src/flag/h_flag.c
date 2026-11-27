/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** h_flag
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include "../../lib/my/include/my.h"
#include "struct_my_sudo.h"
#include "return_macro.h"
#include "macro.h"

static
char *my_memset(char *buff)
{
    for (int i = 0; i < 33; i++)
        buff[i] = 0;
    return buff;
}

int h_flag(int ac, char **av)
{
    char buff[33] = {0};
    int fd = 0;
    int size = 0;

    fd = open(H_FLAG_TXT, O_RDONLY);
    if (fd == -1)
        return ERROR_EXIT;
    size = read(fd, buff, 32);
    while (size > 0) {
        my_putstr(buff);
        my_memset(buff);
        size = read(fd, buff, 32);
    }
    close(fd);
    if (ac > 2 || strlen(av[1]) > 2)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}