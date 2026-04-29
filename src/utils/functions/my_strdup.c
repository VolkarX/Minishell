/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strdup
*/

#include "../../../include/my.h"

char *my_strdup(const char *str)
{
    int len;
    char *copy;

    if (str == NULL) {
        return NULL;
    }
    len = my_strlen(str);
    copy = malloc(len + 1);
    if (copy != NULL) {
        copy = my_strcpy(copy, str);
    }
    return copy;
}
