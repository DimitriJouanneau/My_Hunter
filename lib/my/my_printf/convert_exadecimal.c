/*
** EPITECH PROJECT, 2025
** convert exadecimal
** File description:
** convert decimal to char * of exadecimal
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int len_size(unsigned int n)
{
    int size = 0;

    while (n != 0){
        n = n / 16;
        size += 1;
    }
    return size;
}

int len_size2(unsigned int n)
{
    int size = 0;

    while (n != 0){
        n = n / 16;
        size += 1;
    }
    return size;
}

int print_hexadecimal_uppercase(unsigned int n, int width,
    int decimal_precision)
{
    char *hexadecimal;
    int size = len_size2(n);
    int i;

    if (n == 0)
        return my_putchar('0', 0, 0);
    hexadecimal = malloc(sizeof(char) * (size + 1));
    if (!hexadecimal)
        return -1;
    hexadecimal[size] = '\0';
    for (i = size - 1; i != -1; i--){
        if ((n % 16) > 9)
            hexadecimal[i] = 'A' + ((n % 16) - 10);
        else
            hexadecimal[i] = (n % 16) + '0';
        n = n / 16;
    }
    return my_put_str(hexadecimal, width, size);
}

int print_hexadecimal_lowercase(unsigned long n, int width,
    int decimal_precision)
{
    char *hexadecimal;
    int size = len_size2(n);
    int i;

    if (n == 0)
        return my_putchar('0', 0, 0);
    hexadecimal = malloc(sizeof(char) * (size + 1));
    if (!hexadecimal)
        return -1;
    hexadecimal[size] = '\0';
    for (i = size - 1; i != -1; i--){
        if ((n % 16) > 9)
            hexadecimal[i] = 'a' + ((n % 16) - 10);
        else
            hexadecimal[i] = (n % 16) + '0';
        n = n / 16;
    }
    return my_put_str(hexadecimal, width, size);
}
