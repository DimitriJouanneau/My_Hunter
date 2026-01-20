/*
** EPITECH PROJECT, 2025
** my_show_word_array
** File description:
** Task03
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putchar3(char c)
{
    write(1, &c, 1);
}

int my_putstr3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar3(str[i]);
        i++;
    }
    return 0;
}

int my_show_word_array(char *const *tab)
{
    char test_word_array;
    char *result = malloc(sizeof(char) * (test_word_array + 1));
    int i = 0;

    while (tab[i] != 0) {
        my_putstr3(tab[i]);
        my_putchar3('\n');
        i++;
    }
    return 0;
    free(result);
}
