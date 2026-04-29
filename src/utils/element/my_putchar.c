/*
** EPITECH PROJECT, 2026
** mysh
** File description:
** my_putchar
*/

#include "../../../include/my.h"

int my_putchar(const char c)
{
    return write(1, &c, 1);
}
