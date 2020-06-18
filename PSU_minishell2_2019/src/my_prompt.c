/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_prompt
*/

#include <unistd.h>

void my_prompt(void)
{
    if (isatty(STDIN_FILENO) == 1)
        write(1, "$>", 2);
}