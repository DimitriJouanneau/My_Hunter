/*
** EPITECH PROJECT, 2025
** my_strcapitalize
** File description:
** Task10
*/

#include "my.h"

char *my_strlowcase2(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}

void space_maj(char *str, int i)
{
    if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
        str[i + 1] = str[i + 1] - 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase2(str);
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z')
                || (str[i] >= '0' && str[i] <= '9'))) {
            space_maj(str, i);
        }
        i++;
    }
    return str;
}
