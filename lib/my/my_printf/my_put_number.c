/*
** EPITECH PROJECT, 2025
** my_put_number
** File description:
** My put number
*/

#include "my_printf.h"

int my_intlen(int nb)
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

int if_min_size(int nb, int width, int decimal_precision)
{
    if (nb == -2147483648) {
        my_putchar('-', 0, 0);
        my_putchar('2', 0, 0);
        my_put_number(147483648, 0, 0);
        return 0;
    }
    return 0;
}

int negative_number(int *nb, int width)
{
    int len2 = my_intlen(*nb);
    int len = 0;

    if (*nb < 0) {
        my_putchar('-', 0, 0);
        *nb = -*nb;
        len++;
    }
    return len;
}

int my_put_number(int nb, int width, int decimal_precision)
{
    int len2 = my_intlen(nb);
    int len = 0;

    if (nb == -2147483648) {
        if_min_size(nb, width, decimal_precision);
        return 11;
    }
    if (len2 < width)
        print_width(width, len2);
    negative_number(&nb, width);
    len2++;
    if (nb >= 10)
        len += my_put_number(nb / 10, 0, 0);
    my_putchar((nb % 10) + '0', 0, 0);
    len++;
    if (len2 > width)
        return len;
    else
        return width;
}
