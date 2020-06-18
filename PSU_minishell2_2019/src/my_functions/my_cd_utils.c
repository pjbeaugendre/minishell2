/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd2
*/

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"
#include "functions.h"

void edit_pwd_old(info_t *inf, char *str, char *pwd)
{
    int size = my_strlen(str);
    char *new = NULL;

    for (int j = 0; inf->env[j] != NULL; j++) {
        if (my_strncmp(inf->env[j], str, size) == 0
        && inf->env[j][size] != '\0') {
            new = my_strcat(str, pwd);
            inf->env[j] = new;
            return;
        }
    }
}

void display_cd_error(char *str)
{
    struct stat n;

    if (stat(str, &n) != -1 && !S_ISDIR(n.st_mode)) {
        my_pstrerr(str);
        my_pstrerr(": Not a directory.\n");
    } else {
        my_pstrerr(str);
        my_pstrerr(": No such file or directory.\n");
    }
}

char *get_home(info_t *inf)
{
    for (int j = 0; inf->env[j] != NULL; j++) {
        if (my_strncmp(inf->env[j], "HOME=", 5) == 0
        && inf->env[j][5] != '\0') {
            return (inf->env[j] + 5);
        }
    }
    return ("\0");
}

char *get_oldpwd(info_t *inf)
{
    for (int j = 0; inf->env[j] != NULL; j++) {
        if (my_strncmp(inf->env[j], "OLDPWD=", 7) == 0
        && inf->env[j][7] != '\0')
            return (inf->env[j] + 7);
        if (my_strncmp(inf->env[j], "OLDPWD=", 7) == 0
        && inf->env[j][7] == '\0')
            return ("\n");
    }
    return ("\0");
}

void check_oldpwd(info_t *inf)
{
    char *oldpwd = get_oldpwd(inf);
    char *pwd = NULL;
    char *arg[3];

    pwd = getcwd(pwd, 1024);
    arg[0] = "";
    arg[1] = "OLDPWD";
    arg[2] = pwd;
    if (oldpwd[0] == '\0')
        new_env_line_w_value(arg, inf);
    if (oldpwd[0] == '\n')
        for (int j = 0; inf->env[j] != NULL; j++)
            if (my_strncmp(inf->env[j], "OLDPWD=", 7) == 0)
                inf->env[j] = my_strcat("OLDPWD=", pwd);
}