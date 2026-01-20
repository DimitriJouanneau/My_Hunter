/*
** EPITECH PROJECT, 2025
** check_flags_two.c
** File description:
** %e - %E - %x - %X - %o
*/

#include "my_printf.h"

int check_e_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_scientific(va_arg(args, double), 'e', decimal_precision);
}

int check_upper_e_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_scientific(va_arg(args, double), 'E', decimal_precision);
}

int check_upper_x_specifier(va_list args, int width, int decimal_precision)
{
    return print_hexadecimal_uppercase(va_arg(args, int), width,
        decimal_precision);
}

int check_x_specifier(va_list args, int width, int decimal_precision)
{
    return print_hexadecimal_lowercase(va_arg(args, int), width,
        decimal_precision);
}

int check_o_specifier(va_list args, int width, int decimal_precision)
{
    return print_octal(va_arg(args, int), width, decimal_precision);
}
