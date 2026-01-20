/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** Task07
*/
#include "my.h"

int my_strlen5(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
        if (s1[i] != s2[i]) {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        i++;
    }
    return 0;
}
