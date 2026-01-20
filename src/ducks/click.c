/*
** EPITECH PROJECT, 2025
** click.c
** File description:
** click
*/

#include "../../include/my_hunter.h"

int is_bird_clicked(bird_t *bird, sfVector2i *mouse_pos)
{
    sfFloatRect bbox = sfSprite_getGlobalBounds(bird->sprite);

    return sfFloatRect_contains(&bbox, mouse_pos->x, mouse_pos->y);
}
