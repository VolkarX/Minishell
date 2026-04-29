/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** get_env
*/

#include "../../../include/my.h"

char *my_getenv(const char *name, char **envp)
{
    int i = 0;
    int j;
    int len = my_strlen(name);

    if (!name || !envp)
        return NULL;
    for (i = 0; envp[i] != NULL; i++) {
        for (j = 0; j < len && envp[i][j] == name[j]; j++);
        if (j == len && envp[i][len] == '=')
            return &envp[i][len + 1];
    }
    return NULL;
}
