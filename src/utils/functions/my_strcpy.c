/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strcpy
*/

#include "../../../include/my.h"

char *my_strcpy(char *copy, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
