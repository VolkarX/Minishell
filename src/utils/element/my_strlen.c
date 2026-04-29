/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strlen
*/

#include "../../../include/my.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
