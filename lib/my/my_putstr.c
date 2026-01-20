/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** Try c
*/

#include "my.h"
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
