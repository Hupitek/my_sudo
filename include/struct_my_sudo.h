/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** struct_my_sudo
*/

#ifndef STRUCT_MY_SUDO_H_
    #define STRUCT_MY_SUDO_H_

typedef struct my_sudo_s {
    char *user;
    char *pwd_user;
    char *salt;
    char *hash_algo;
    char *pwd_input;
    char *pwd_input_hash;
} my_sudo_t;


#endif /* !STRUCT_MY_SUDO_H_ */
