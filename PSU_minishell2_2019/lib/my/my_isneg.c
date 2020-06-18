/*
** EPITECH PROJECT, 2019
** pierre-joseph.beaugendre@epitech.eu
** File description:
** write N if negative or P if Positive or null
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    my_putchar('\n');
    return (0);
}