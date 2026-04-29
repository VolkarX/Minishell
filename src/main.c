/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** Main file
*/

#include "../include/my.h"

static int init_data(char **buffer, char ***my_envp, char **envp)
{
    *buffer = malloc(sizeof(char) * 32);
    if (*buffer == NULL) {
        perror("malloc");
        return 84;
    }
    *my_envp = copy_env(envp);
    if (*my_envp == NULL) {
        perror("malloc");
        free(*buffer);
        return 84;
    }
    return 0;
}

static int shell_loop(shell_t *shell, size_t *bufsize, char **buffer)
{
    ssize_t read;
    char *cleaned;

    while (1) {
        if (isatty(STDIN_FILENO))
            mini_printf("$> ");
        read = getline(buffer, bufsize, stdin);
        if (read == -1)
            break;
        shell->buffer = *buffer;
        cleaned = clearstring(*buffer);
        if (cleaned == NULL) {
            perror("malloc");
            return 84;
        }
        shell->cleaned = cleaned;
        shell->last_status = handle_cmd(cleaned, shell, shell->envp);
        free(cleaned);
    }
    return shell->last_status;
}

int main(int argc, char **argv, char **envp)
{
    size_t bufsize = 32;
    char *buffer = NULL;
    char **my_envp = NULL;
    shell_t shell = {0, my_envp, buffer, NULL, NULL};
    int status;

    (void)argc;
    (void)argv;
    if (init_data(&buffer, &my_envp, envp) == 84)
        return 84;
    shell.envp = my_envp;
    shell.buffer = buffer;
    status = shell_loop(&shell, &bufsize, &buffer);
    free(buffer);
    free_env(my_envp);
    return status;
}
