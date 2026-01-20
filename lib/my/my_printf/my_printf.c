/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** Main my_printf file
*/

#include "my_printf.h"

const format_t formats[] = {
    {'d', (void *)check_d_specifier},
    {'i', (void *)check_i_specifier},
    {'s', (void *)check_s_specifier},
    {'c', (void *)check_c_specifier},
    {'%', (void *)check_modulo_specifier},
    {'e', (void *)check_e_specifier},
    {'E', (void *)check_upper_e_specifier},
    {'X', (void *)check_upper_x_specifier},
    {'x', (void *)check_x_specifier},
    {'o', (void *)check_o_specifier},
    {'p', (void *)check_p_specifier},
    {'f', (void *)check_f_specifier},
    {'u', (void *)check_u_specifier},
    {'\0', NULL},
};

int get_width(const char *format, int *index)
{
    int width = 0;

    while (format[*index] >= '0' && format[*index] <= '9') {
        width = (width * 10) + (format[*index] - '0');
        (*index)++;
    }
    return width;
}

int print_var(const char *format, int *index, va_list args)
{
    int decimal_precision = 6;
    int i = 0;
    int count = 0;
    int width = get_width(format, &(*index));
    char type_var;

    if (format[*index] == '.') {
        (*index)++;
        decimal_precision = 0;
        while (format[*index] >= '0' && format[*index] <= '9') {
            decimal_precision = decimal_precision * 10 + (format[*index] - '0');
            (*index)++;
        }
    }
    type_var = format[*index];
    for (; formats[i].type != '\0'; i++) {
        if (formats[i].type == type_var)
            return formats[i].f(args, width, decimal_precision);
    }
    return count;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int sum = 0;
    va_list args;

    if (!format) {
        return -1;
    }
    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%'){
            i++;
            sum += print_var(format, &i, args);
        } else {
            sum += my_putchar(format[i], 0, 0);
        }
        i++;
    }
    va_end(args);
    return sum;
}
