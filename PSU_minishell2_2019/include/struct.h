/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct info
{
    char **env;
    char **path;
    int setval;
    int return_val;
    int check_path;
    int need_dup;
    int w_dup;
    int fd;
    int w_close;
}info_t;

#endif
