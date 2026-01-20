/*
** EPITECH PROJECT, 2025
** concat_params.c
** File description:
** Task02
*/

#include <stdlib.h>
#include "my.h"

int my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return 0;
}

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char *result = malloc(sizeof(char) * (argc + 1));
    int k = 0;

    for (i = 0; i < argc; i++) {
        j = 0;
        while (argv[i][j]) {
            result[k] = argv[i][j];
            k++;
            j++;
        }
        result[k] = '\n';
        k++;
    }
    result[k - 1] = '\0';
    return result;
    free(result);
}
