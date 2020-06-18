/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_pstrerr
*/

void my_putcherr(char c);

int my_pstrerr(char const *str)
{
    int x = 0;

    for (x = 0; str[x] != '\0'; x++)
        my_putcherr(str[x]);
    return (0);
}