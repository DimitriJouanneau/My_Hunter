/*
** EPITECH PROJECT, 2025
** my_put_str.c
** File description:
** My put str file
*/

#include "my_printf.h"

static int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int print_good_format(char *str, int width, int decimal_precision)
{
    int len = my_strlen(str);

    if (width < decimal_precision) {
        my_put_str(str, 0, 0);
        print_width(width, len);
    }
    if (len < width && decimal_precision < len)
        print_width(width + len * 2 - decimal_precision, len + width);
    if (len < decimal_precision && decimal_precision > width)
        print_width(width - decimal_precision, len);
    if (len < width && decimal_precision > width)
        print_width(width, len - (len - decimal_precision));
    else
        print_width(width, len);
    return 0;
}

int my_put_str(char *str, int width, int decimal_precision)
{
    int i = 0;
    int len = my_strlen(str);

    if (!str) {
        write(1, "(null)", 6);
        return 6;
    }
    if (decimal_precision == 6)
        decimal_precision = len;
    print_good_format(str, width, decimal_precision);
    while (str[i] != '\0' && i < decimal_precision) {
        my_putchar(str[i], 0, 0);
        i++;
        len++;
    }
    if (width > i)
        return width;
    if (width <= i)
        return i;
    return 0;
}
