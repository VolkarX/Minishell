/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strchr
*/

#include "../../../include/my.h"

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    if ((char)c == '\0') {
        return (char *)s;
    }
    return NULL;
}
