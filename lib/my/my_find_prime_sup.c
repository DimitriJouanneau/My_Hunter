/*
** EPITECH PROJECT, 2025
** my_find_prime_sup
** File description:
** Try c
*/

#include "my.h"

int my_is_prime2(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (1) {
        if (my_is_prime2(nb)) {
            return nb;
        }
        nb++;
    }
}
