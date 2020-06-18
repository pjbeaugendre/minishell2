/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirections_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

int check_redirect(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '>' || str[i] == '<')
            return (1);
    return (0);
}

int getnb_chev(char *str)
{
    if (str[0] == '1')
        return (1);
    if (str[0] == '2')
        return (2);
    return (0);
}