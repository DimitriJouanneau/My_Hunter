/*
** EPITECH PROJECT, 2025
** convert octal
** File description:
** convert integer in char * of octal
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int len_size3(unsigned int n)
{
    int size = 0;

    while (n != 0){
        n = n / 8;
        size += 1;
    }
    return size;
}

int print_octal(unsigned int n, int width, int decimal_precision)
{
    char *octal;
    int size = len_size3(n);
    int i;

    if (n == 0)
        return my_putchar('0', 0, 0);
    octal = malloc(sizeof(char) * (size + 1));
    if (!octal)
        return -1;
    octal[size] = '\0';
    for (i = size - 1; i != -1; i--){
        octal[i] = (n % 8) + '0';
        n = n / 8;
    }
    return my_put_str(octal, width, size);
    free(octal);
}
