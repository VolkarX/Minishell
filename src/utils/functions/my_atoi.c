/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
