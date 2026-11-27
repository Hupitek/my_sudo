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
int get_pwd_input(my_sudo_t *my_sudo);
void free_my_sudo(my_sudo_t *my_sudo);
int compare_pwd(char *mdp, char *mdp_compare);
int hash_pwd(my_sudo_t *my_sudo);
int exec_command(int ac, char **av);
void init_my_sudo(my_sudo_t *my_sudo);
int get_sudoers_data(my_sudo_t *my_sudo);
int no_flag(int ac, char **av, char **env, my_sudo_t *my_sudo);
int parcing_arg(int ac, char **av, my_sudo_t *my_sudo);
int h_flag(int ac, char **av);

#endif /* !FUNC_MY_SUDO_H_ */
