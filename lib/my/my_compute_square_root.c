/*
** EPITECH PROJECT, 2025
** my_print_digits
** File description:
** Try c
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int result = 1;

    if (nb < 0) {
        return 0;
    }
    while (result * result < nb) {
        result++;
    }
    if (result * result == nb) {
        return result;
    } else {
        return 0;
    }
}
