/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    char temp;
    int i = 0;

    for (i = 0; i < length; i++, length--) {
        temp = str[i];
        str[i] = str[length];
        str[length] = temp;
    }
    return (str);
}