/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** Task02
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
