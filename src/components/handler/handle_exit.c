/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_exit
*/

#include "../../../include/my.h"

int handle_exit(char **args, shell_t *shell)
{
    int exit_code = shell->last_status;

    if (args[1] != NULL) {
        if (!is_number(args[1])) {
            mini_printf("exit: bad number\n");
            free(shell->args);
            free(shell->cleaned);
            free(shell->buffer);
            free_env(shell->envp);
            exit(84);
        }
        exit_code = my_atoi(args[1]);
    }
    free(shell->args);
    free(shell->cleaned);
    free(shell->buffer);
    free_env(shell->envp);
    exit(exit_code);
}
