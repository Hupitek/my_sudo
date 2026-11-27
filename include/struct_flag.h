/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** struct_flag
*/

#ifndef STRUCT_FLAG_H_
    #define STRUCT_FLAG_H_
    #include "struct_my_sudo.h"

typedef enum {
    NO_FLAG,
    U_FLAG,
    G_FLAG,
    H_FLAG
} falg_t;

typedef struct flag_s {
    int(*func)(int ac, char **av, my_sudo_t *my_sudo);
    falg_t flag;
} flag_t;

#endif /* !STRUCT_FLAG_H_ */
