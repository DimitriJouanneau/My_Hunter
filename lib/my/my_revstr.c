/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** Task03
*/

#include "my.h"

int my_strlen3(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int i;
    int j;
    char tmp;

    j = my_strlen3(str) - 1;
    i = 0;
    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}
