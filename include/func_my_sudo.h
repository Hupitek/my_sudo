/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** func_my_sudo
*/

#ifndef FUNC_MY_SUDO_H_
    #define FUNC_MY_SUDO_H_
    #include "struct_my_sudo.h"

int get_user(char **env, my_sudo_t *my_sudo);
int get_shadow_data(my_sudo_t *my_sudo);

#endif /* !FUNC_MY_SUDO_H_ */
