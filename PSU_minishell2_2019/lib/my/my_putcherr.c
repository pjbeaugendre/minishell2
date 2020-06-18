/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_putcherr
*/

#include <unistd.h>

void my_putcherr(char c)
{
    write(2, &c, 1);
}