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
int get_pwd(char *line, my_sudo_t *my_sudo)
{
    int i = 0;

    my_sudo->pwd_user = malloc(sizeof(char) * (my_strcharlen(line, ':') + 1));
    if (my_sudo->pwd_user == NULL)
        return ERROR_EXIT;
    for (; i < my_strcharlen(line, ':'); i++)
        my_sudo->pwd_user[i] = line[i];
    my_sudo->pwd_user[i] = '\0';
    return SUCCESS_EXIT;
}

static
int get_salt(char *line, my_sudo_t *my_sudo)
{
    int i = 0;

    my_sudo->salt = malloc(sizeof(char) * (my_strcharlen(line, '$') + 2));
    if (my_sudo->salt == NULL)
        return ERROR_EXIT;
    my_sudo->salt[0] = '$';
    for (; i < my_strcharlen(line, '$'); i++)
        my_sudo->salt[i + 1] = line[i];
    my_sudo->salt[i + 1] = '\0';
    line += i;
    if (get_pwd(line, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

static
int get_hash_algo(char *line, my_sudo_t *my_sudo)
{
    int i = 0;

    line += 1;
    my_sudo->hash_algo = malloc(sizeof(char) * (my_strcharlen(line, '$') + 2));
    if (my_sudo->hash_algo == NULL)
        return ERROR_EXIT;
    my_sudo->hash_algo[0] = '$';
    for (; i < my_strcharlen(line, '$'); i++)
        my_sudo->hash_algo[i + 1] = line[i];
    my_sudo->hash_algo[i + 1] = '\0';
    line += i + 1;
    if (get_salt(line, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

static
int get_user_info(my_sudo_t *my_sudo, char *buff)
{
    char *line = my_strstr(buff, my_sudo->user);
    int i = 0;

    if (line == NULL) {
        return ERROR_EXIT;
    }
    for (; line[i] != ':'; i++);
    i++;
    line += i;
    if (get_hash_algo(line, my_sudo) == ERROR_EXIT)
        return ERROR_EXIT;
    return SUCCESS_EXIT;
}

int fill_buff(char *buff, struct stat *sarg)
{
    int fd = 0;

    fd = open(ETC_SHADOW_PATH, O_RDONLY);
    if (fd == -1)
        return ERROR_EXIT;
    read(fd, buff, sarg->st_size);
    buff[sarg->st_size] = '\0';
    close(fd);
    return SUCCESS_EXIT;
}

int get_shadow_data(my_sudo_t *my_sudo)
{
    char *buff;
    struct stat sarg;

    if (stat(ETC_SHADOW_PATH, &sarg) == -1)
        return ERROR_EXIT;
    buff = malloc(sizeof(char) * (sarg.st_size + 1));
    if (buff == NULL)
        return ERROR_EXIT;
    if (fill_buff(buff, &sarg) == ERROR_EXIT)
        return ERROR_EXIT;
    if (get_user_info(my_sudo, buff) == ERROR_EXIT) {
        free(buff);
        return ERROR_EXIT;
    }
    free(buff);
    return SUCCESS_EXIT;
}
