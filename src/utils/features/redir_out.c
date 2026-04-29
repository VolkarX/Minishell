/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** redir_out
*/

#include "../../../include/my.h"

static int find_redir_out(char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '>' && line[i + 1] != '>')
            return i;
        i++;
    }
    return -1;
}

static char **build_split(char *left, char *right)
{
    char **tab = malloc(sizeof(char *) * 3);

    if (tab == NULL)
        return NULL;
    tab[0] = clearstring(left);
    tab[1] = clearstring(right);
    tab[2] = NULL;
    if (tab[0] == NULL || tab[1] == NULL || tab[0][0] == '\0' ||
        tab[1][0] == '\0') {
        free_split(tab);
        return NULL;
    }
    return tab;
}

char **split_redir_out(char *line)
{
    char *dup = my_strdup(line);
    char **tab;
    int pos;

    if (dup == NULL)
        return NULL;
    pos = find_redir_out(dup);
    if (pos == -1) {
        free(dup);
        return NULL;
    }
    dup[pos] = '\0';
    tab = build_split(dup, dup + pos + 1);
    free(dup);
    return tab;
}
