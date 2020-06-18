/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_show_array
*/

#include "my.h"

void my_show_array(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}