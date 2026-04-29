/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** handle_cd
*/

#include "../../../include/my.h"

static char *get_home_directory(char **envp)
{
    char *home = my_getenv("HOME", envp);

    if (home == NULL) {
        mini_printf("cd: HOME not set\n");
    }
    return home;
}

static char *get_oldpwd_directory(char **envp)
{
    char *oldpwd = my_getenv("OLDPWD", envp);

    if (oldpwd == NULL) {
        mini_printf("cd: OLDPWD not set\n");
    }
    return oldpwd;
}

static char *get_target_directory(char **args, char **envp)
{
    if (args[1] == NULL || my_strcmp(args[1], "~") == 0) {
        return get_home_directory(envp);
    } else if (my_strcmp(args[1], "-") == 0) {
        return get_oldpwd_directory(envp);
    } else {
        return args[1];
    }
}

int handle_cd(char **args, char **envp)
{
    char *target = get_target_directory(args, envp);

    if (target == NULL) {
        return 1;
    }
    if (chdir(target) != 0) {
        mini_printf("cd: %s: No such file or directory\n", target);
        return 1;
    }
    return 0;
}
