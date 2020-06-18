/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** cd
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

int move_home(info_t *inf, int i)
{
    char *pwd = NULL;
    char *home = get_home(inf);

    pwd = getcwd(pwd, 1024);
    if (chdir(home) != -1) {
        edit_pwd_old(inf, "OLDPWD=", pwd);
        pwd = getcwd(pwd, 1024);
        edit_pwd_old(inf, "PWD=", pwd);
        free(pwd);
        return (0);
    } else {
        if (i == 0) {
            my_pstrerr("No $home variable set.\n");
            free(pwd);
        } else if (i == 1) {
            my_pstrerr("cd: No home directory.\n");
            free(pwd);
        }
        return (1);
    }
}

int move_back(info_t *inf)
{
    char *pwd = NULL;
    char *oldpwd = get_oldpwd(inf);

    pwd = getcwd(pwd, 1024);
    if (chdir(oldpwd) != -1) {
        edit_pwd_old(inf, "OLDPWD=", pwd);
        pwd = getcwd(pwd, 1024);
        edit_pwd_old(inf, "PWD=", pwd);
        free(pwd);
        return (0);
    } else {
        display_cd_error("-");
        free(pwd);
        return (1);
    }
}

int redirection(info_t *inf, char *arg)
{
    if (arg[0] == '-' && arg[1] == '\0')
        return (move_back(inf));
    else if ((arg[0] == '-' && arg[1] == '-' && arg[2] == '\0')
    || (arg[0] == '~' && arg[1] == '\0'))
        return (move_home(inf, 0));
    return (do_cd(inf, arg));
}

int do_cd(info_t *inf, char *arg)
{
    char *pwd = NULL;

    pwd = getcwd(pwd, 1024);
    if (chdir(arg) != -1) {
        edit_pwd_old(inf, "OLDPWD=", pwd);
        pwd = getcwd(pwd, 1024);
        edit_pwd_old(inf, "PWD=", pwd);
        free(pwd);
        return (0);
    } else {
        display_cd_error(arg);
        free(pwd);
        return (1);
    }
}

int cd(char **arg, info_t *inf)
{
    int j = 0;

    for (; arg[j]; j++);
    if (j > 2) {
        my_pstrerr("cd: Too many arguments.\n");
        return (1);
    }
    check_oldpwd(inf);
    if (j == 2)
        return (redirection(inf, arg[1]));
    else
        return (move_home(inf, 1));
    return (0);
}
