/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** get_sudoers_data
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "macro.h"
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

int get_sudoers_data(my_sudo_t *my_sudo)
{
    struct stat sarg;
    char *buff;
    int fd;

    if (stat(ETC_SHADOW_PATH, &sarg) == -1)
        return ERROR_EXIT;
    buff = malloc(sizeof(char) * (sarg.st_size + 1));
    if (buff == NULL)
        return ERROR_EXIT;
    fd = open(ETC_SUDOERS_PATH, O_RDONLY);
    read(fd, buff, sarg.st_size);
    close(fd);
    if (my_strstr(buff, my_sudo->user) == NULL)
        my_sudo->perm = false;
    return SUCCESS_EXIT;
}
