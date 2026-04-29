/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_unsetenv
*/

#include "../../../include/my.h"

static int index_env_finder(char *name, char **envp)
{
    int i = 0;
    int len = my_strlen(name);
    int j;

    for (i = 0; envp[i] != NULL; i++) {
        for (j = 0; j < len && envp[i][j] == name[j]; j++);
        if (j == len && envp[i][len] == '=')
            return i;
    }
    return -1;
}

static void shift_env_vars(int idx, char **envp)
{
    int i = idx;

    free(envp[idx]);
    while (envp[i + 1] != NULL) {
        envp[i] = envp[i + 1];
        i++;
    }
    envp[i] = NULL;
}

int handle_unsetenv(char **args, shell_t *shell)
{
    int idx;

    if (args[1] == NULL) {
        mini_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    idx = index_env_finder(args[1], shell->envp);
    if (idx != -1)
        shift_env_vars(idx, shell->envp);
    return 0;
}
