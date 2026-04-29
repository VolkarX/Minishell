/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_putstr
*/

#include "../../../include/my.h"

int my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
