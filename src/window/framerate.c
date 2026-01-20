/*
** EPITECH PROJECT, 2025
** framerate.c
** File description:
** framerate
*/

#include "../../include/my_hunter.h"

void set_framerate(sfRenderWindow *window, unsigned int fps)
{
    sfRenderWindow_setFramerateLimit(window, fps);
}
