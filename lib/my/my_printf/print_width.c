/*
** EPITECH PROJECT, 2025
** print_width
** File description:
** print the ' ' before value
*/

#include "my_printf.h"

int print_width(int width, int len)
{
    int i;

    if (len > width)
        return 0;
    else {
        for (i = 0; i < (width - len); i++){
            my_putchar(' ', 0, 0);
        }
    }
    return (width - len);
}
