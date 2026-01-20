/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** Task01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *copy;
    int j;

    while (src[i] != '\0') {
        i++;
    }
    copy = malloc(sizeof(char) * (i + 1));
    if (copy == 0) {
        return 0;
    }
    for (j = 0; j < i; j++) {
        copy[j] = src[j];
    }
    copy[i] = '\0';
    return copy;
}
