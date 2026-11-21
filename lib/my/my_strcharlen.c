/*
** EPITECH PROJECT, 2026
** my_sudo
** File description:
** my_strcharlen
*/

int my_strcharlen(char *str, char end)
{
    int len = 0;

    for (int i = 0; str[i] != end; i++)
        len++;
    return len;
}