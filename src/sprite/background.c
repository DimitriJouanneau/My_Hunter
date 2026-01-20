/*
** EPITECH PROJECT, 2025
** background.c
** File description:
** background
*/

#include "../../include/my_hunter.h"

sfSprite *create_background(const char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("assets/sprites/backgrounds/bg_1080*608.png",
        NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
