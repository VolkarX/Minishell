/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_cmd
*/

#include "../../../include/my.h"

static int is_fr_lang(char **envp)
{
    char *lang = my_getenv("LANG", envp);

    if (lang == NULL)
        return 0;
    if (lang[0] == 'f' && lang[1] == 'r')
        return 1;
    return 0;
}

static void exec_child_process(char **args, char **envp)
{
    char *full_path = find_in_path(args[0], envp);

    if (full_path == NULL) {
        if (is_fr_lang(envp) == 1)
            mini_printf("%s: Commande introuvable.\n", args[0]);
        else
            mini_printf("%s: Command not found.\n", args[0]);
        exit(1);
    }
    execve(full_path, args, envp);
    perror("execve");
    exit(84);
}

static int handle_echo_status(shell_t *shell)
{
    mini_printf("%d\n", shell->last_status);
    return 0;
}

static int is_builtin_cmd(char **args, shell_t *shell)
{
    if (my_strcmp(args[0], "exit") == 0)
        handle_exit(args, shell);
    if (my_strcmp(args[0], "cd") == 0)
        return handle_cd(args, shell->envp);
    if (my_strcmp(args[0], "setenv") == 0)
        return handle_setenv(args, shell);
    if (my_strcmp(args[0], "unsetenv") == 0)
        return handle_unsetenv(args, shell);
    return -1;
}

static int is_echo_status(char **args, shell_t *shell)
{
    if (my_strcmp(args[0], "echo") == 0 && args[1] != NULL &&
        my_strcmp(args[1], "$?") == 0)
        return handle_echo_status(shell);
    return -1;
}

static int signal_status(int status)
{
    int sig = WTERMSIG(status);

    if (sig == SIGSEGV)
        my_putstr("Segmentation fault");
    else if (sig == SIGFPE)
        my_putstr("Floating exception");
    else
        my_putstr(strsignal(sig));
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    my_putstr("\n");
    return 128 + sig;
}

int exec_cmd(char **args, char **envp)
{
    pid_t pid = fork();
    int status;

    if (pid == 0)
        exec_child_process(args, envp);
    if (pid < 0)
        return 84;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        return signal_status(status);
    return 0;
}

static int dispatch_special(char *command, shell_t *shell, char **envp)
{
    if (my_strchr(command, ';') != NULL)
        return handle_sequence(command, shell, envp);
    if (my_strchr(command, '<') != NULL && my_strchr(command, '|') == NULL)
        return handle_redir_in(command, shell, envp);
    if (my_strchr(command, '>') != NULL && my_strchr(command, '|') == NULL)
        return handle_redir_out(command, shell, envp);
    if (my_strchr(command, '|') != NULL)
        return handle_pipe(command, shell, envp);
    return -2;
}

int handle_cmd(char *command, shell_t *shell, char **envp)
{
    char **args;
    int status;

    command[my_strcspn(command, "\n")] = 0;
    status = dispatch_special(command, shell, envp);
    if (status != -2)
        return status;
    args = parse_args(command);
    if (args == NULL)
        return 0;
    shell->args = args;
    status = is_builtin_cmd(args, shell);
    if (status == -1)
        status = is_echo_status(args, shell);
    if (status == -1)
        status = exec_cmd(args, envp);
    free(args);
    return status;
}
