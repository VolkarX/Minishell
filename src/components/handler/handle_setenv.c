/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_setenv
*/

#include "../../../include/my.h"

static int count_env_var(char **envp)
{
    int count = 0;

    while (envp[count] != NULL)
        count++;
    return count;
}

static char *env_entry_creator(char *name, char *value)
{
    int len = my_strlen(name) + my_strlen(value) + 2;
    char *entry = malloc(sizeof(char) * len);
    int i = 0;
    int j = 0;

    while (name[i] != '\0') {
        entry[i] = name[i];
        i++;
    }
    entry[i] = '=';
    i++;
    while (value[j] != '\0') {
        entry[i] = value[j];
        i++;
        j++;
    }
    entry[i] = '\0';
    return entry;
}

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

static void exist_var_updater(int idx, char **envp, char *entry)
{
    free(envp[idx]);
    envp[idx] = entry;
}

static int add_new_var(char **envp, char *entry)
{
    int count = count_env_var(envp);

    envp[count] = entry;
    envp[count + 1] = NULL;
    return 0;
}

static int print_env(char **envp)
{
    int i = 0;

    while (envp[i] != NULL) {
        mini_printf("%s\n", envp[i]);
        i++;
    }
    return 0;
}

int handle_setenv(char **args, shell_t *shell)
{
    int idx;
    char *entry;
    char *value;

    if (args[1] == NULL)
        return print_env(shell->envp);
    if (args[2] != NULL && args[3] != NULL) {
        mini_printf("setenv: Too many arguments.\n");
        return 1;
    }
    value = (args[2] == NULL) ? "" : args[2];
    entry = env_entry_creator(args[1], value);
    idx = index_env_finder(args[1], shell->envp);
    if (idx != -1)
        exist_var_updater(idx, shell->envp, entry);
    else
        add_new_var(shell->envp, entry);
    return 0;
}
