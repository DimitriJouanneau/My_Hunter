/*
** EPITECH PROJECT, 2025
** my_int_to_str.c
** File description:
** my_int_to_str
*/

void my_int_to_str(int n, char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    while (n > 0) {
        str[i] = (n % 10) + '0';
        i++;
        n /= 10;
    }
    str[i] = '\0';
    for (j = 0; j < i / 2; j++) {
        tmp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tmp;
    }
}
