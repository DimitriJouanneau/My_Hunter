/*
** EPITECH PROJECT, 2025
** check_flags.c
** File description:
** %d - %i - %s - %c - %%
*/

#include "my_printf.h"

int check_d_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_number(va_arg(args, int), width, decimal_precision);
}

int check_i_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_number(va_arg(args, int), width, decimal_precision);
}

int check_s_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_str(va_arg(args, char *), width, decimal_precision);
}

int check_c_specifier(va_list args, int width, int decimal_precision)
{
    return my_putchar((char)va_arg(args, int), width, decimal_precision);
}

int check_modulo_specifier(va_list args, int width, int decimal_precision)
{
    return my_putchar('%', width, decimal_precision);
}
