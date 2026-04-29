/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** parser
*/

#include "../../../include/my.h"

int check_cmd(char *command)
{
    if (command[0] == '\0')
        return 0;
    if (command[0] == '\n')
        return 0;
    if (command[0] == '\t')
        return 0;
    if (command[0] == ' ')
        return 0;
    return 1;
}

char **parse_args(char *command)
{
    char **args = malloc(sizeof(char *) * 64);
    char *token;
    int i = 0;

    if (check_cmd(command) == 0) {
        free(args);
        return NULL;
    }
    token = strtok(command, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}
