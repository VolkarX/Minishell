/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** clearstring
*/

#include "../../include/my.h"

static int is_space_or_tab(char c)
{
    return (c == ' ' || c == '\t');
}

static void skip_spaces(char *src, int *i)
{
    while (is_space_or_tab(src[*i]))
        (*i)++;
}

static void process_char(char *src, char *dest, int *i, int *j)
{
    if (!is_space_or_tab(src[*i])) {
        dest[*j] = src[*i];
        (*j)++;
        (*i)++;
    } else {
        dest[*j] = ' ';
        (*j)++;
        skip_spaces(src, i);
    }
}

char *clearstring(char *src)
{
    char *dest = malloc(my_strlen(src) + 1);
    int i = 0;
    int j = 0;

    if (!dest)
        return NULL;
    skip_spaces(src, &i);
    while (src[i] != '\0' && src[i] != '\n')
        process_char(src, dest, &i, &j);
    if (j > 0 && dest[j - 1] == ' ')
        j--;
    dest[j] = '\0';
    return dest;
}
