/*
** EPITECH PROJECT, 2025
** my_unsigned_number
** File description:
** Unsigned number - 0 to 4 294 967 295
*/

#include "my_printf.h"

int my_unsigned_intlen(int nb)
{
    unsigned int len = 0;

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

unsigned int my_unsigned_number(unsigned int nb, unsigned int width)
{
    unsigned int len2 = my_unsigned_intlen(nb);
    unsigned int len = 0;

    if (len2 < width)
        print_width(width, len2);
    if (nb >= 10)
        len += my_unsigned_number(nb / 10, 0);
    my_putchar((nb % 10) + '0', 0, 0);
    len++;
    if (len2 > width)
        return len;
    else
        return width;
}
