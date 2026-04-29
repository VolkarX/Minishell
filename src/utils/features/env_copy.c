/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** env_copy
*/

#include "../../../include/my.h"

static int count_env_vars(char **envp)
{
    int count = 0;

    while (envp[count] != NULL)
        count++;
    return count;
}

static int add_nlspath_if_missing(char **new_envp, int i)
{
    char *val = "NLSPATH=/usr/share/locale/%L/LC_MESSAGES/%N.cat:"
        "/usr/share/locale/%l/LC_MESSAGES/%N.cat";

    if (my_getenv("NLSPATH", new_envp) != NULL)
        return i;
    new_envp[i] = my_strdup(val);
    if (new_envp[i] == NULL)
        return -1;
    i++;
    new_envp[i] = NULL;
    return i;
}

char **copy_env(char **envp)
{
    int count = count_env_vars(envp);
    char **new_envp = malloc(sizeof(char *) * (count + 100));
    int i = 0;

    if (new_envp == NULL)
        return NULL;
    while (i < count) {
        new_envp[i] = my_strdup(envp[i]);
        i++;
    }
    new_envp[i] = NULL;
    if (add_nlspath_if_missing(new_envp, i) == -1) {
        free_env(new_envp);
        return NULL;
    }
    return new_envp;
}

void free_env(char **envp)
{
    int i = 0;

    if (envp == NULL)
        return;
    while (envp[i] != NULL) {
        free(envp[i]);
        i++;
    }
    free(envp);
}
