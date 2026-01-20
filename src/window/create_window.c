/*
** EPITECH PROJECT, 2025
** create_window.c
** File description:
** create_window
*/

#include "../../include/my_hunter.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height
    , char *title)
{
    sfVideoMode mode = {width, height, 32};
    sfUint32 style = sfClose | sfResize;

    return sfRenderWindow_create(mode, title, style, NULL);
}
