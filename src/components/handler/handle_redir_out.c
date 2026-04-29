/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_redir_out
*/

#include "../../../include/my.h"

static int redir_status(int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);
    return 0;
}

static int bad_redir(char **parts)
{
    if (parts[0] == NULL || parts[1] == NULL)
        return 1;
    if (parts[2] != NULL)
        return 1;
    if (parts[0][0] == '\0' || parts[1][0] == '\0')
        return 1;
    return 0;
}

static void run_child(int fd, char *cmd, shell_t *shell, char **envp)
{
    dup2(fd, STDOUT_FILENO);
    close(fd);
    exit(handle_cmd(cmd, shell, envp));
}

static int run_fork(pid_t pid, int fd, char **parts)
{
    int status;

    if (pid == -1) {
        close(fd);
        free_split(parts);
        return 84;
    }
    close(fd);
    waitpid(pid, &status, 0);
    free_split(parts);
    return redir_status(status);
}

int handle_redir_out(char *line, shell_t *shell, char **envp)
{
    char **parts = split_redir_out(line);
    int fd;
    pid_t pid;

    if (parts == NULL)
        return 1;
    if (bad_redir(parts) == 1) {
        free_split(parts);
        return 1;
    }
    fd = open(parts[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror(parts[1]);
        free_split(parts);
        return 1;
    }
    pid = fork();
    if (pid == 0)
        run_child(fd, parts[0], shell, envp);
    return run_fork(pid, fd, parts);
}
