/*
** EPITECH PROJECT, 2025
** destroy_bird.c
** File description:
** destroy bird
*/

#include "../../include/my_hunter.h"

void destroy_bird(bird_t *bird)
{
    if (!bird)
        return;
    sfTexture_destroy(bird->texture);
    sfSprite_destroy(bird->sprite);
    free(bird);
}
