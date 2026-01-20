/*
** EPITECH PROJECT, 2025
** my_put_float.c
** File description:
** print a float
*/

#include "my_printf.h"
#include <stdio.h>

int my_floatlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        nb = -nb;
        len++;
    }
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

int get_rounded(int nb)
{
    if ((nb % 10) > 5)
        nb += 10 - (nb % 10);
    return nb / 10;
}

int my_put_float(double nb, int width, int decimal_precision)
{
    int entier = (int) nb;
    int decimal;
    int size = 1 + my_floatlen(entier) + decimal_precision;
    int base_1 = 1;

    for (int i = 1; i < decimal_precision + 2; i++){
        base_1 *= 10;
    }
    decimal = get_rounded((int) ((nb - entier) * base_1));
    if (decimal < 0)
        decimal = -decimal;
    print_width(width, size);
    my_put_number(entier, 0, 0);
    my_putchar('.', 0, 0);
    my_put_number(decimal, 0, 0);
    if (width > size)
        return width;
    else
        return size;
}
