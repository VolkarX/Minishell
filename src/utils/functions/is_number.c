/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** is_number
*/

int is_number(char *str)
{
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
