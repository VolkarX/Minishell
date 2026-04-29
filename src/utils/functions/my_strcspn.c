/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_strcspn
*/

#include "../../../include/my.h"

int my_strcspn(const char *s, const char *reject)
{
    int i = 0;

    while (s[i] != '\0') {
        if (my_strchr(reject, s[i]) != NULL) {
            return i;
        }
        i++;
    }
    return i;
}
