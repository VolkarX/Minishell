/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** semicolon
*/

#include "../../../include/my.h"

static int count_parts(char *line)
{
    int i = 0;
    int nb = 1;

    while (line[i] != '\0') {
        if (line[i] == ';')
            nb++;
        i++;
    }
    return nb;
}

static void init_tab(char **tab, int nb)
{
    int i = 0;

    while (i <= nb) {
        tab[i] = NULL;
        i++;
    }
}

static int fill_parts(char **tab, char *dup)
{
    char *save = NULL;
    char *tok = strtok_r(dup, ";", &save);
    int i = 0;

    while (tok != NULL) {
        tab[i] = clearstring(tok);
        if (tab[i] == NULL)
            return 84;
        i++;
        tok = strtok_r(NULL, ";", &save);
    }
    tab[i] = NULL;
    return 0;
}

char **split_semicolon(char *line)
{
    int nb = count_parts(line);
    char *dup = my_strdup(line);
    char **tab;

    if (dup == NULL)
        return NULL;
    tab = malloc(sizeof(char *) * (nb + 1));
    if (tab == NULL) {
        free(dup);
        return NULL;
    }
    init_tab(tab, nb);
    if (fill_parts(tab, dup) == 84) {
        free_split(tab);
        free(dup);
        return NULL;
    }
    free(dup);
    return tab;
}

void free_split(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
