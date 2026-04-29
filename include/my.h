/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** Library
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

typedef struct shell_s {
    int last_status;
    char **envp;
    char *buffer;
    char *cleaned;
    char **args;
} shell_t;

char **parse_args(char *command);
char *find_in_path(char *cmd, char **envp);
int handle_cd(char **args, char **envp);
int handle_cmd(char *command, shell_t *shell, char **envp);
int handle_sequence(char *line, shell_t *shell, char **envp);
int handle_pipe(char *line, shell_t *shell, char **envp);
int handle_redir_out(char *line, shell_t *shell, char **envp);
int handle_redir_in(char *line, shell_t *shell, char **envp);
int handle_setenv(char **args, shell_t *shell);
int handle_unsetenv(char **args, shell_t *shell);
int handle_exit(char **args, shell_t *shell);
char *clearstring(char *src);
char *my_strcpy(char *copy, const char *src);
int my_strlen(const char *str);
char *my_strdup(const char *str);
int my_putstr(const char *str);
int my_putchar(const char c);
int mini_printf(const char *format, ...);
int my_strcmp(const char *s1, const char *s2);
int my_strcspn(const char *s, const char *reject);
char *my_strchr(const char *s, int c);
char *my_getenv(const char *name, char **envp);
char **copy_env(char **envp);
void free_env(char **envp);
int my_atoi(char *str);
int is_number(char *str);
char **split_semicolon(char *line);
char **split_pipe(char *line);
char **split_redir_out(char *line);
char **split_redir_in(char *line);
void free_split(char **tab);

#endif
