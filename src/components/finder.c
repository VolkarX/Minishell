/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** finder
*/

#include "../../include/my.h"

static char *build_full_path(char *dir, char *cmd)
{
    char *full_path = malloc(1024);
    int i = 0;
    int j = 0;

    while (dir[i] != '\0') {
        full_path[i] = dir[i];
        i++;
    }
    full_path[i] = '/';
    i++;
    while (cmd[j] != '\0') {
        full_path[i] = cmd[j];
        i++;
        j++;
    }
    full_path[i] = '\0';
    return full_path;
}

char *slash_cmd(char *cmd)
{
    if (access(cmd, X_OK) == 0)
        return my_strdup(cmd);
    return NULL;
}

char *find_in_path(char *cmd, char **envp)
{
    char *path = my_getenv("PATH", envp);
    char *path_copy;
    char *dir;
    char *full_path;

    if (my_strchr(cmd, '/') != NULL)
        return slash_cmd(cmd);
    path_copy = my_strdup(path);
    dir = strtok(path_copy, ":");
    while (dir != NULL) {
        full_path = build_full_path(dir, cmd);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}
