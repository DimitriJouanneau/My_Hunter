/*
** EPITECH PROJECT, 2025
** printf.h
** File description:
** .h for connecting all file
*/



#ifndef _MY_PRINTF_H_
    #define _MY_PRINTF_H_
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>

int print_width(int width, int len);
int my_putchar(char c, int width, int decimal_precision);
int my_put_number(int nb, int width, int decimal_precision);
int my_put_str(char *str, int width, int decimal_precision);
int check_d_specifier(va_list arg, int width, int decimal_precision);
int check_i_specifier(va_list arg, int width, int decimal_precision);
int check_s_specifier(va_list arg, int width, int decimal_precision);
int check_c_specifier(va_list arg, int width, int decimal_precision);
int check_modulo_specifier(va_list arg, int width, int decimal_precision);
int my_printf(const char *format, ...);
int check_e_specifier(va_list args, int width, int decimal_precision);
int check_upper_e_specifier(va_list args, int width, int decimal_precision);
int my_put_scientific(double n, char type, int decimal_precision);
int print_hexadecimal_uppercase(unsigned int n, int width,
    int decimal_precision);
int check_upper_x_specifier(va_list args, int width, int decimal_precision);
int print_hexadecimal_lowercase(unsigned long n,
    int width, int decimal_precision);
int check_x_specifier(va_list args, int width, int decimal_precision);
int check_o_specifier(va_list args, int width, int decimal_precision);
int print_octal(unsigned int n, int width, int decimal_precision);
int check_p_specifier(va_list args, int width, int decimal_precision);
int my_put_float(double nb, int width, int decimal_precision);
int check_f_specifier(va_list args, int width, int decimal_precision);
unsigned int my_unsigned_number(unsigned int nb, unsigned int width);
unsigned int check_u_specifier(va_list args, unsigned int width);

typedef struct {
    char type;
    int (*f)(va_list, int width, int decimal_precision);
} format_t;

#endif /* _MY_PRINTF_H_ */
