/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** Try c
*/

#include "my.h"

int get_sign(const char *str, int *index)
{
    int sign = 1;
    int i = 0;

    while (str[i] && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            sign = -sign;
        }
        i++;
    }
    *index = i;
    return sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = get_sign(str, &i);
    long result = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        if (sign == 1 && result > 2147483647) {
            return 0;
        }
        if (sign == - 1 && result < -2147483648) {
            return 0;
        }
        i++;
    }
    return (int)(result * sign);
}
