/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_sequence
*/

#include "../../../include/my.h"

static int run_parts(char **parts, shell_t *shell, char **envp)
{
    int i = 0;
    int status = shell->last_status;

    while (parts[i] != NULL) {
        if (parts[i][0] != '\0')
            status = handle_cmd(parts[i], shell, envp);
        i++;
    }
    return status;
}

int handle_sequence(char *line, shell_t *shell, char **envp)
{
    char **parts = split_semicolon(line);
    int status;

    if (parts == NULL) {
        perror("malloc");
        return 84;
    }
    status = run_parts(parts, shell, envp);
    free_split(parts);
    return status;
}
