/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epiech.eu
** File description:
** my_getnbr
*/

#include <stdio.h>

int check_char(char const *str);

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int n = 0;
    int x = 0;

    if (check_char(str) == 1)
        return (0);
    for (i; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            n++;
    }
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        x = j;
        j = j * 10 + str[i] -'0';
    }
    if (n % 2 != 0){
        j = -j;
    }
    return (j);
}

int check_char(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            return (1);
        if (str[i] >= 97 && str[i] <= 122)
            return (1);
    }
    return (0);
}