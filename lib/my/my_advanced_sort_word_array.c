/*
** EPITECH PROJECT, 2025
** my_advanced_sort_word_array
** File description:
** Not sure it's correct
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static void swap(char **a, char **b, int (*cmp)(char const *, char const *))
{
    char *tmp;

    if (cmp(*a, *b) > 0) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int my_advanced_sort_word_array(
    char **tab,
    int (*cmp)(char const *, char const *)
)
{
    int i = 0;
    int j = 0;

    if (tab == NULL || cmp == NULL) {
        return 0;
    }
    for (i = 0; tab[i] != NULL; i++) {
        for (j = i + 1; tab[j] != NULL; j++) {
            swap(&tab[i], &tab[j], cmp);
        }
    }
    return 0;
}
