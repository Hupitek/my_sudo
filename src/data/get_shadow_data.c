/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** get_shadow_data
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "macro.h"
#include "return_macro.h"
#include "struct_my_sudo.h"
#include "../../lib/my/include/my.h"

static
int get_pwd(my_sudo_t *my_sudo, char *buff)
{
    char *line = my_strstr(buff, my_sudo->user);
    int i = 0;

    if (line == NULL)
        return ERROR_EXIT;
    for (; line[i] != ':'; i++);
    i++;
    line += i;
    i = 0;
    my_sudo->pwd_user = malloc(sizeof(char) * (my_strcharlen(line, ':') + 1));
    if (my_sudo->pwd_user == NULL)
        return ERROR_EXIT;
    for (; i < my_strcharlen(line, ':'); i++)
        my_sudo->pwd_user[i] = line[i];
    my_sudo->pwd_user[i + 1] = '\0';
    return SUCCESS_EXIT;
}

int get_shadow_data(my_sudo_t *my_sudo)
{
    char *buff;
    struct stat sarg;
    int fd = 0;

    if (stat(ETC_SHADOW_PATH, &sarg) == -1)
        return ERROR_EXIT;
    buff = malloc(sizeof(char) * (sarg.st_size + 1));
    if (!buff)
        return ERROR_EXIT;
    fd = open(ETC_SHADOW_PATH, O_RDONLY);
    read(fd, buff, sarg.st_size);
    if (get_pwd(my_sudo, buff) == ERROR_EXIT) {
        free(buff);
        return ERROR_EXIT;
    }
    close(fd);
    free(buff);
    return SUCCESS_EXIT;
}
