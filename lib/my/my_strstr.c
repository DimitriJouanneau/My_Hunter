/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** Task05
*/

#include "my.h"

int my_strlen4(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char counting(char *str, char const *to_find)
{
    int countstr = my_strlen4(str);
    int countfind = my_strlen4(to_find);
    int i;
    int k;
    int found;

    for (k = 0; k < countfind; k++) {
        if (str[i + k] != to_find[k]) {
            found = 0;
        }
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int countstr = my_strlen4(str);
    int countfind = my_strlen4(to_find);
    int i;
    int k;
    int found;

    if (countfind > countstr) {
        return 0;
    }
    for (i = 0; i < countstr - countfind; i++) {
        found = 1;
        counting(str, to_find);
    }
    if (found == 1) {
        return str;
    }
    return 0;
}
