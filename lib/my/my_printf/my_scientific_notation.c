/*
** EPITECH PROJECT, 2025
** my_scientific_notation.c
** File description:
** Recreate the %e and %E
*/

#include "my_printf.h"

static int change_negative_sign(int n)
{
    if (n < 0) {
        n = -n;
    }
    return n;
}

static int put_exponent(int exp, char type)
{
    int count = 0;
    int e;

    count += my_putchar(type, 0, 0);
    if (exp >= 0) {
        count += my_putchar('+', 0, 0);
    } else {
        count += my_putchar('-', 0, 0);
    }
    e = change_negative_sign(exp);
    if (e < 10) {
        count += my_putchar('0', 0, 0);
    }
    count += my_put_number(e, 0, 0);
    return count;
}

double rounded_up(double n, int decimal_precision)
{
    int i = 0;
    double factor = 1.0;
    long long integer_part;
    double dec_part;

    for (i = 0; i < decimal_precision; i++) {
        factor *= 10;
    }
    n = n * factor;
    integer_part = (long long)n;
    dec_part = n - integer_part;
    if (dec_part >= 0.5) {
        integer_part++;
    }
    n = (double)integer_part / factor;
    return n;
}

int decimal_part(double n, int decimal_precision)
{
    int count = 0;
    long long int_part = (long long)n;
    double decimal = n - (double)int_part;
    int digit;
    int i = 0;

    count += my_put_number(int_part, 0, 0);
    count += my_putchar('.', 0, 0);
    for (i = 0; i < decimal_precision; i++) {
        decimal *= 10.0;
        digit = (long long)(decimal + 1e-9);
        count += my_putchar('0' + digit, 0, 0);
        decimal -= (double)digit;
    }
    return count;
}

int calcul(double *n)
{
    int exp = 0;

    while (*n >= 10.0) {
        *n /= 10.0;
        exp++;
    }
    while (*n < 1.0) {
        *n *= 10.0;
        exp--;
    }
    return exp;
}

int if_n_equal_zero(double n, int decimal_precision)
{
    int i = 0;
    int count = 0;

    if (n != 0.0)
        return 0;
    count += my_putchar('0', 0, 0);
    count += my_putchar('.', 0, 0);
    for (i = 0; i < decimal_precision; i++) {
        count += my_putchar('0', 0, 0);
    }
    count += my_putchar('e', 0, 0);
    count += my_putchar('+', 0, 0);
    count += my_putchar('0', 0, 0);
    count += my_putchar('0', 0, 0);
    return count;
}

int my_put_scientific(double n, char type, int decimal_precision)
{
    int count = 0;
    int exp = 0;
    long long zero_check = if_n_equal_zero(n, decimal_precision);

    if (zero_check > 0)
        return zero_check;
    if (n < 0) {
        count += my_putchar('-', 0, 0);
        n = -n;
    }
    exp = calcul(&n);
    n = rounded_up(n, decimal_precision);
    if (n >= 10.0) {
        n /= 10.0;
        exp++;
    }
    count += decimal_part(n, decimal_precision);
    count += put_exponent(exp, type);
    return count;
}
