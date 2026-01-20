/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** My putchar return 1
*/

#include "my_printf.h"

int my_putchar(char c, int width, int decimal_precision)
{
    print_width(width, 1);
    write(1, &c, 1);
    if (width > 1)
        return width;
    else
        return 1;
}
