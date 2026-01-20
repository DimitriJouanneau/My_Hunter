/*
** EPITECH PROJECT, 2025
** my_sort_word_array
** File description:
** lib
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

static void swap(char **a, char **b)
{
    char *tmp;

    if (my_strcmp(*a, *b) > 0) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int my_sort_word_array(char **tab)
{
    int i = 0;
    int j = 0;

    if (!tab)
        return 0;
    for (i = 0; tab[i] != NULL; i++) {
        for (j = i + 1; tab[j] != NULL; j++)
            swap(&tab[i], &tab[j]);
    }
    return 0;
}
