/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** Try c.
*/

#include "my.h"
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
