/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_pipe
*/

#include "../../../include/my.h"

static int bad_pipe(char **parts)
{
    if (parts[0] == NULL || parts[1] == NULL)
        return 1;
    if (parts[2] != NULL)
        return 1;
    if (parts[0][0] == '\0' || parts[1][0] == '\0')
        return 1;
    return 0;
}

static void exec_left(int *fd, char *cmd, shell_t *shell, char **envp)
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    exit(handle_cmd(cmd, shell, envp));
}

static void exec_right(int *fd, char *cmd, shell_t *shell, char **envp)
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    exit(handle_cmd(cmd, shell, envp));
}

static int run_children(int *fd, char **parts, shell_t *shell, char **envp)
{
    pid_t p1 = fork();
    pid_t p2;
    int st2;

    if (p1 == 0)
        exec_left(fd, parts[0], shell, envp);
    p2 = fork();
    if (p2 == 0)
        exec_right(fd, parts[1], shell, envp);
    close(fd[0]);
    close(fd[1]);
    waitpid(p1, NULL, 0);
    waitpid(p2, &st2, 0);
    if (WIFEXITED(st2))
        return WEXITSTATUS(st2);
    if (WIFSIGNALED(st2))
        return 128 + WTERMSIG(st2);
    return 0;
}

int handle_pipe(char *line, shell_t *shell, char **envp)
{
    char **parts = split_pipe(line);
    int fd[2];
    int status;

    if (parts == NULL)
        return 84;
    if (bad_pipe(parts) == 1) {
        free_split(parts);
        return 1;
    }
    if (pipe(fd) == -1) {
        free_split(parts);
        return 84;
    }
    status = run_children(fd, parts, shell, envp);
    free_split(parts);
    return status;
}
