/*
** EPITECH PROJECT, 2025
** check_flags_three.c
** File description:
** %p
*/

#include "my_printf.h"

int check_p_specifier(va_list args, int width, int decimal_precision)
{
    void *pointeur;
    unsigned long ex;

    my_putchar('0', width, 0);
    my_putchar('x', width, 0);
    pointeur = va_arg(args, void*);
    ex = (unsigned long) pointeur;
    return 2 + print_hexadecimal_lowercase(ex, 0, 0);
}

int check_f_specifier(va_list args, int width, int decimal_precision)
{
    return my_put_float(va_arg(args, double)
        , width, decimal_precision);
}

unsigned int check_u_specifier(va_list args, unsigned int width)
{
    return my_unsigned_number(va_arg(args, unsigned int), width);
}
